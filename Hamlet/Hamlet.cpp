#include "Hamlet.h"

extern FILE *LOG_FILE;

int Run_Hamlet (struct Basic_Data *structure)
{
    MY_ASSERT (structure, "struct Basic_Data *structure",
               "Pointer on the structure is NULL", { return ERROR; });

    structure -> file_input_ptr = Open_File (structure -> file_input_name, "rb");
    if (structure -> file_input_ptr == NULL)
        return ERROR;


    structure -> n_symbs = Define_File_Size (structure -> file_input_ptr);
    if (structure -> n_symbs == ERROR)
        return ERROR;


    structure -> buffer = Make_Buffer (structure -> file_input_ptr, structure -> n_symbs);
    if (structure -> buffer == NULL)
        return ERROR;

    if (Close_File (structure -> file_input_ptr, structure -> file_input_name) == ERROR)
        return ERROR;

    structure -> n_strings = Make_Strings (structure -> buffer, structure -> n_symbs);
    if (structure -> n_strings == ERROR)
        return ERROR;

    if (Make_Arrays (structure) == ERROR)
        return ERROR;

    if (Find_String_Borders (structure -> str_ar, structure -> buffer, structure -> n_symbs) == ERROR)
        return ERROR;

    if (Sort_And_Print (structure -> str_ar, structure -> str_arr_ptr, structure -> n_strings, structure -> file_sort_name) == ERROR)
        return ERROR;

    if (Memory_Free (structure -> str_ar, structure -> str_arr_ptr, structure -> buffer) == ERROR)
        return ERROR;

    return NO_ERRORS;
}

FILE *Open_File (const char *file_name, const char *mode)
{
    MY_ASSERT (file_name, "const char *file_name", "Pointer on the file name is NULL",       {return NULL;});
    MY_ASSERT (mode,      "const char *mode",      "Pointer on the read/write mode is NULL", {return NULL;});

    FILE *file_ptr = fopen (file_name, mode);

    MY_ASSERT (file_ptr, "FILE *file_ptr", "Impossible to open file", {return NULL;});

    return file_ptr;
}

long Define_File_Size (FILE *file_ptr)
{
    MY_ASSERT (file_ptr, "FILE *file_ptr", "Pointer on the file is NULL", {return ERROR;});

    long start_pos = ftell (file_ptr);

    if (fseek (file_ptr, 0L, SEEK_END))
        MY_ASSERT (0, "fseek ()", "fseek () working error", {return ERROR;});

    long n_symbs = ftell (file_ptr);
    MY_ASSERT (n_symbs != -1L, "long n_symbs", "ftell () working error", {return ERROR;});

    if (fseek (file_ptr, start_pos, SEEK_SET))
        MY_ASSERT (0, "fseek ()", "fseek () working error", {return ERROR;});

    return n_symbs;
}

int Close_File (FILE *file_ptr, const char *file_name)
{
    MY_ASSERT (file_ptr,  "FILE *file_ptr",        "Pointer on the file is NULL",      {return ERROR;});
    MY_ASSERT (file_name, "const char *file_name", "Pointer on the file name is NULL", {return ERROR;});

    int closing_result = fclose (file_ptr);
    MY_ASSERT (!closing_result, "int closing_result", "Impossible to close the file", {return ERROR;});

    return NO_ERRORS;
}

char *Make_Buffer (FILE *file_ptr, const long n_symbs)
{
    MY_ASSERT (file_ptr,    "FILE *file_ptr",     "Pointer on the file is NULL", {return NULL;});
    MY_ASSERT (n_symbs > 0, "const long n_symbs", "Expected positive value",     {return NULL;});

    char *buffer = (char *)calloc (n_symbs + 1, sizeof (char));
    MY_ASSERT (buffer, "char *buffer", "Impossible to allocate memory for buffer", {return NULL;});

    size_t read_symbs = fread (buffer, sizeof (char), n_symbs, file_ptr);

    MY_ASSERT (read_symbs == (size_t)n_symbs, "size_t read_symbs",
               "The number of read symbols differs from the expected one", {return NULL;});

    return buffer;
}

int Make_Strings (char *buffer, const long n_symbs)
{
    MY_ASSERT (buffer,      "char *buffer",       "Pointer on the buffer is NULL", {return ERROR;});
    MY_ASSERT (n_symbs > 0, "const long n_symbs", "Expected positive value",       {return ERROR;});

    int n_strings = 0, symb_i = 0;
    bool is_new_line = false;

    while (symb_i < n_symbs)
    {
        if (buffer[symb_i] == '\n' || buffer[symb_i] == '\r')
        {
            is_new_line = true;

            n_strings++;
            while (isspace (buffer[symb_i]) || buffer[symb_i] == '\0')
            {
                buffer[symb_i] = '\0';
                symb_i++;
                if (symb_i == n_symbs)
                    break;
            }
        }
        else
        {
            symb_i++;
            is_new_line = false;
        }

    }

    if (!is_new_line)
        n_strings++;

    return n_strings;
}

int Make_Arrays (struct Basic_Data *structure)
{
    MY_ASSERT (structure, "struct Basic_Data *structure", "Pointer on the structure is NULL", {return ERROR;});

    structure -> str_ar = (struct string *)calloc (structure -> n_strings + 1, sizeof (struct string));
    MY_ASSERT (structure -> str_ar, "structure -> str_ar", "Impossible to allocate memory for array of structures", {return ERROR;});

    structure -> str_arr_ptr = (struct string **)calloc (structure -> n_strings + 1, sizeof (struct string *));
    MY_ASSERT (structure -> str_arr_ptr, "structure -> str_arr_ptr",
               "Impossible to allocate memory for array of pointers on structures", {return ERROR;});

    for (int index = 0; index < structure -> n_strings; index++)
        (structure -> str_arr_ptr)[index] = &(structure -> str_ar)[index];

    return NO_ERRORS;
}

int Find_String_Borders (struct string *str_ar, char *buffer, const long n_symbs)
{
    MY_ASSERT (str_ar,      "struct string *str_ar", "Pointer on the array of structures is NULL", {return ERROR;});
    MY_ASSERT (buffer,      "char *buffer",          "Pointer on the buffer is NULL",              {return ERROR;});
    MY_ASSERT (n_symbs > 0, "const long n_symbs",    "Expected positive value",                    {return ERROR;});

    int str_i = 0;
    long symb_i = 0;
    bool in_str = true;
    bool str_beginning = true;

    while (symb_i < n_symbs)
    {
        // printf ("symb_i = %ld\n", n_symbs);
        if (buffer[symb_i] == '\0')
        {
            if (in_str)
            {
                in_str = false;

                int end_i = symb_i - 1;
                while (isspace(buffer[end_i]))
                    end_i--;

                str_ar[str_i].ending = &buffer[end_i];
                // printf ("symb_i = %d\n", symb_i);
                str_i++;
            }
            while (symb_i < n_symbs && buffer[symb_i] == '\0') {
                
                // printf ("symb_i = %d\n", symb_i);
                symb_i++;
            }
        }
        else
        {
            if (in_str)
            {
                if (str_beginning)
                {
                    while (isspace(buffer[symb_i]) || buffer[symb_i] == '\0')
                        symb_i++;

                    
                    str_ar[str_i].beginning = &buffer[symb_i];
                    str_beginning = false;
                }
                symb_i++;
            }
            else
                in_str = str_beginning = true;
        }

        
    }

    return NO_ERRORS;
}

int Open_Logfile (void)
{
    LOG_FILE = fopen ("log_file.log", "wb");

    if (!LOG_FILE)
    {
        LOG_FILE = stderr;
        MY_ASSERT (0, "LOG_FILE", "Impossible to open log file", {return ERROR;});
    }

    fprintf (LOG_FILE, "%s", PREAMBLE);

    return NO_ERRORS;
}

int My_Assert (bool condition, const char *file, int line, const char *fun_name, const char *var_name, const char *err_name)
{
    assert (fun_name);
    assert (var_name);
    assert (err_name);
    assert (line > 0);

    if (!condition)
    {
        fprintf (LOG_FILE, "File: %s\n",                                   file);
        fprintf (LOG_FILE, "Line: %d\n",                                   line);
        fprintf (LOG_FILE, "Function with error: %s\n",                    fun_name);
        fprintf (LOG_FILE, "Variable or function that caused error: %s\n", var_name);
        fprintf (LOG_FILE, "Error description: %s\n\n",                    err_name);

        return 1;
    }

    return 0;
}

int Memory_Free (struct string *str_ar, struct string **str_arr_ptr, char *buffer)
{
    MY_ASSERT (str_ar,      "struct string *str_ar",      "Pointer on the array of structures is NULL",             {return ERROR;});
    MY_ASSERT (str_arr_ptr, "struct string *str_arr_ptr", "Pointer on the array of pointers on structures is NULL", {return ERROR;});

    free (str_ar);
    free (str_arr_ptr);
    free (buffer);

    return NO_ERRORS;
}
