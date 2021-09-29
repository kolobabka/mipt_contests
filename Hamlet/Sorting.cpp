#include "Hamlet.h"

int Sort_And_Print (struct string *str_ar, struct string **str_arr_ptr,
                    const int n_strings, const char *file_sort_name)
{
    MY_ASSERT (str_ar,         "struct string *str_ar",       "Pointer on the array of structures is NULL",             {return ERROR;});
    MY_ASSERT (str_arr_ptr,    "struct string **str_arr_ptr", "Pointer on the array of pointers on structures is NULL", {return ERROR;});
    MY_ASSERT (n_strings > 0,  "const int n_strings",         "Expected positive value",                                {return ERROR;});
    MY_ASSERT (file_sort_name, "const char *file_sort_name",  "Pointer on the name of output file is NULL",             {return ERROR;});

    FILE *file_sort_ptr = Open_File (file_sort_name, "wb");
    if (file_sort_ptr == NULL)
        return ERROR;

    if (Beginning      (file_sort_ptr, str_arr_ptr, n_strings) == ERROR ||
        Ending         (file_sort_ptr, str_arr_ptr, n_strings) == ERROR ||
        Print_Original (file_sort_ptr, str_ar,      n_strings) == ERROR)
        return ERROR;

    if (Close_File (file_sort_ptr, file_sort_name) == ERROR)
        return ERROR;

    return NO_ERRORS;
}

int Beginning (FILE *file_sort_ptr, struct string **str_arr_ptr, const int n_strings)
{
    MY_ASSERT (file_sort_ptr, "FILE *file_sort_ptr",         "Pointer on the output file is NULL",                     {return ERROR;});
    MY_ASSERT (str_arr_ptr,   "struct string **str_arr_ptr", "Pointer on the array of pointers on structures is NULL", {return ERROR;});
    MY_ASSERT (n_strings > 0, "const int n_strings",         "Expected positive value",                                {return ERROR;});

    // qsort (str_arr_ptr, n_strings, sizeof (struct string *), My_Strcmp_Beginning);

    if (My_QSort ((void **)str_arr_ptr, 0, n_strings - 1, My_Strcmp_Beginning) == ERROR)
        return ERROR;



    //K_R_qsort ((void **)str_arr_ptr, 0, n_strings - 1, My_Strcmp_Beginning);

    fprintf(file_sort_ptr, "HERE COMES BEGINNING SORTING\n\n");

    for (int str_i = 0; str_i < n_strings; str_i++)
        fprintf (file_sort_ptr, "%s\n", str_arr_ptr[str_i] -> beginning);

    Check_Order (str_arr_ptr, n_strings, true);

    return NO_ERRORS;
}

int Ending (FILE *file_sort_ptr, struct string **str_arr_ptr, const int n_strings)
{
    MY_ASSERT (file_sort_ptr, "FILE *file_sort_ptr",         "Pointer on the output file is NULL",                     {return ERROR;});
    MY_ASSERT (str_arr_ptr,   "struct string **str_arr_ptr", "Pointer on the array of pointers on structures is NULL", {return ERROR;});
    MY_ASSERT (n_strings > 0, "const int n_strings",         "Expected positive value",                                {return ERROR;});

    // qsort (str_arr_ptr, n_strings, sizeof (struct string *), My_Strcmp_Ending);

    if (My_QSort ((void **)str_arr_ptr, 0, n_strings - 1, My_Strcmp_Ending) == ERROR)
        return ERROR;

    //K_R_qsort ((void **)str_arr_ptr, 0, n_strings - 1, My_Strcmp_Ending);

    fprintf (file_sort_ptr, "\n\nHERE COMES END SORTING\n\n");
    for (int str_i = 0; str_i < n_strings; str_i++)
        fprintf (file_sort_ptr, "%70s\n", str_arr_ptr[str_i] -> beginning);

    Check_Order (str_arr_ptr, n_strings, false);

    return NO_ERRORS;
}
//NOT FOR RELEASE!!!
void Check_Order (struct string **str_arr_ptr, int n_strings, bool mode)
{
    for (int str_i = 0; str_i < n_strings - 1; str_i++)
    {
        int result = 0;

        if (mode)
            result = My_Strcmp_Beginning (str_arr_ptr + str_i, str_arr_ptr + str_i + 1);
        else
            result = My_Strcmp_Ending (str_arr_ptr + str_i, str_arr_ptr + str_i + 1);

        if (result == GREATER)
            fprintf (stderr, "Sorting fail.\nString %d: %s\nString %d: %s\n\n",
                    str_i, str_arr_ptr[str_i] -> beginning, str_i + 1, str_arr_ptr[str_i + 1] -> beginning);
    }
}

int Print_Original (FILE *file_sort_ptr, struct string *str_ar, const int n_strings)
{
    MY_ASSERT (file_sort_ptr, "FILE *file_sort_ptr",   "Pointer on the output file is NULL",         {return ERROR;});
    MY_ASSERT (str_ar,        "struct string *str_ar", "Pointer on the array of structures is NULL", {return ERROR;});
    MY_ASSERT (n_strings > 0, "const int n_strings",   "Expected positive value",                    {return ERROR;});

    fprintf (file_sort_ptr, "\n\nHERE COME THE STRINGS IN ORIGINAL ORDER\n\n");
    for (int str_i = 0; str_i < n_strings; str_i++)
        fprintf (file_sort_ptr, "%s\n", str_ar[str_i].beginning);

    return NO_ERRORS;
}
#if 0
int My_QSort (void *arr_ptr[], int n_elements,
              int (*cmp_ptr) (const void *, const void *))
{
    MY_ASSERT (arr_ptr,        "void *arr_ptr[]",                             "Pointer on the array is NULL",      {return ERROR;});
    MY_ASSERT (n_elements > 0, "int n_elements",                              "Expected positive value",           {return ERROR;});
    MY_ASSERT (cmp_ptr,        "int (*cmp_ptr) (const void *, const void *)", "Pointer on the comparator is NULL", {return ERROR;});

    int left = 0;
    int right = n_elements - 1;

    void *middle = arr_ptr[n_elements / 2];
    while (left <= right)
    {
        while ((*cmp_ptr) (arr_ptr + left, &middle) == LESS)
                left++;
        while ((*cmp_ptr) (arr_ptr + right, &middle) == GREATER)
                right--;
        if (left <= right)
            My_Swap (arr_ptr, left++, right--);
    }


    printf ("left = %d, right = %d\n", left, right);
    if (0 < right)
        My_QSort (arr_ptr, right, cmp_ptr);
    //printf ("Here\n");
    if (left < n_elements - 1)
        My_QSort (arr_ptr + left, n_elements - left, cmp_ptr);

    return NO_ERRORS;
}
#endif

int  My_QSort (void* arr_ptr[], int begin, int end, int (*cmp_ptr) (const void *, const void *)) {

    int left  = begin;
    int right = end;
    // exit (1);

    // printf ("right = %d", right);

    void* pivo = arr_ptr[(left + right) / 2];

    while (left <= right) {

        while ((*cmp_ptr) (arr_ptr + left, &pivo) == LESS) {
                ++left;
                // printf ("Left = %d\n", left);
        }

        while ((*cmp_ptr) (arr_ptr + right, &pivo) == GREATER)
                --right;

        

        if (left <= right)
        {
                My_Swap (arr_ptr, left++, right--);
                // left++;
                // right--;
        }
            
        
    }

    if (begin < right)
            My_QSort (arr_ptr, begin, right, cmp_ptr);
    if (end > left)
            My_QSort (arr_ptr, left, end, cmp_ptr);

    return 5;
}

int My_Swap (void *arr_ptr[], int first, int second)
{
    //MY_ASSERT (arr_ptr,     "void *arr_ptr", "Pointer on the array is NULL", {return ERROR;});
    //MY_ASSERT (first >= 0,  "int first",     "Expected not negative value",  {return ERROR;});
    //MY_ASSERT (second >= 0, "int second",    "Expected not negative value",  {return ERROR;});

    // printf ("arr_ptr[first] before = %s\n", ((struct string*) arr_ptr[first])->beginning);

    void *temp = arr_ptr[first];
    arr_ptr[first] = arr_ptr[second];
    arr_ptr[second] = temp;

    // printf ("arr_ptr[first] after = %s\n", ((struct string*) arr_ptr[first])->beginning);
    //printf ("Danya Frolov was here\n");
    return NO_ERRORS;
}


int K_R_qsort (void *arr_ptr[], int l_border, int r_border,
               int (*cmp_ptr) (const void *, const void *))
{
    MY_ASSERT (arr_ptr, "void *arr_ptr[]",                             "Pointer on the array is NULL",      {return ERROR;});
    MY_ASSERT (cmp_ptr, "int (*cmp_ptr) (const void *, const void *)", "Pointer on the comparator is NULL", {return ERROR;});
    return ERROR;

    if (l_border >= r_border)
        return NO_ERRORS;

    My_Swap (arr_ptr, l_border, (l_border + r_border)/2);

    int first = l_border;

    for (int i = l_border + 1; i <= r_border; i++)
        if ((*cmp_ptr) (arr_ptr + i, arr_ptr + l_border) == LESS)
           My_Swap (arr_ptr, ++l_border, i);

    My_Swap (arr_ptr, l_border, first);

    K_R_qsort (arr_ptr, l_border, r_border - 1, cmp_ptr);
    K_R_qsort (arr_ptr, first + 1, r_border, cmp_ptr);

    return NO_ERRORS;
}

int My_Strcmp_Beginning (const void *element_1, const void *element_2)
{

    // printf ("WHY ARE YOU GAY???\n");
    


    assert (((struct string **)element_1)[0]);
    assert (((struct string **)element_2)[0]);
    
    // printf ("TUT YA JIV\n");
    const char *string_1 = ((struct string **)element_1)[0] -> beginning;
    const char *string_2 = ((struct string **)element_2)[0] -> beginning;
    // printf ("TUT YA JIVOY****\n");
    
    while (*string_1 != '\0' && *string_2 != '\0')
    {
        if (toupper (*string_1) == toupper (*string_2))
        {
            string_1++;
            string_2++;
        }
        else
        {
            if (isalpha (*string_1) && isalpha (*string_2))
                break;
            if (!isalpha (*string_1) && *string_1 != '\0')
                string_1++;
            if (!isalpha (*string_2) && *string_2 != '\0')
                string_2++;
        }
    }
    

    if (toupper (*string_1) > toupper (*string_2))
        return GREATER;

    if (toupper (*string_1) < toupper (*string_2))
        return LESS;


    // exit (1);
    return EQUAL;
}

int My_Strcmp_Ending (const void *element_1, const void *element_2)
{
    MY_ASSERT (element_1, "const void *element_1", "Pointer on the first element is NULL",  {return ERROR;});
    MY_ASSERT (element_2, "const void *element_2", "Pointer on the second element is NULL", {return ERROR;});

    const char *string_1 = ((struct string **)element_1)[0] -> ending;
    const char *string_2 = ((struct string **)element_2)[0] -> ending;

    while (*string_1 != '\0' && *string_2 != '\0')
    {
        if (toupper (*string_1) == toupper (*string_2))
        {
            string_1--;
            string_2--;
        }
        else
        {
            if (isalpha (*string_1) && isalpha (*string_2))
                break;
            if (!isalpha (*string_1) && *string_1 != '\0')
                string_1--;
            if (!isalpha (*string_2)  && *string_2 != '\0')
                string_2--;
        }
    }

    if (toupper (*string_1) > toupper (*string_2))
        return GREATER;
    if (toupper (*string_1) < toupper (*string_2))
        return LESS;

    return EQUAL;
}
