#ifndef HAMLET_H_INCLUDED
#define HAMLET_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>


#define MY_ASSERT(condition, var, description, ...)                                 \
{                                                                                   \
    if (!(condition))                                                               \
    {                                                                               \
        My_Assert (false, __FILE__, __LINE__, __FUNCTION__, (var), (description));  \
        __VA_ARGS__;                                                                \
    }                                                                               \
}

struct Basic_Data
{
    FILE *file_input_ptr;
    const char *file_input_name;
    const char *file_sort_name;
    struct string **str_arr_ptr;
    struct string *str_ar;
    char *buffer;
    long n_symbs;
    int n_strings;
};

struct string
{
    char *beginning;
    char *ending;
};

//---------------------------------

const char PREAMBLE[] = "This is log file of the project \"Hamlet Sorting\".\n"
                        "This file will help you to find and fix all the errors.\n\n";

enum COMPARISON
{
    NOT_EQUAL = -2,
    LESS,
    EQUAL,
    GREATER
};

enum ERRORS
{
    NO_ERRORS = -100,
    ERROR
};

const int DECREMENT = -1;
const int INCREMENT = 1;

//---------------------------------

int Run_Hamlet          (struct Basic_Data *structure);
FILE *Open_File         (const char *file_name, const char *mode);
long Define_File_Size   (FILE *file_ptr);
char *Make_Buffer       (FILE *file_ptr, const long n_symbs);
int Close_File          (FILE *file_ptr, const char *file_name);
int Make_Strings        (char *buffer, const long n_symbs);
int Make_Arrays         (struct Basic_Data *structure);
int Find_String_Borders (struct string *str_ar, char *buffer, const long n_symbs);
int Open_Logfile        (void);
int My_Assert           (bool condition, const char *file, int line, const char *fun_name, const char *var_name, const char *err_name);
int Memory_Free         (struct string *str_ar, struct string **str_arr_ptr, char *buffer);

int Sort_And_Print      (struct string *str_ar, struct string **str_arr_ptr, const int n_strings, const char *file_sort_name);
int Beginning           (FILE *file_sort_ptr, struct string **str_arr_ptr, const int n_strings);
int Ending              (FILE *file_sort_ptr, struct string **str_arr_ptr, const int n_strings);
int Print_Original      (FILE *file_sort_ptr, struct string *str_ar, const int n_strings);
void Check_Order        (struct string **str_arr_ptr, int n_strings, bool mode);
int K_R_qsort           (void *arr_ptr[], int l_border, int r_border, int (*cmp_ptr) (const void *, const void *));
//int My_QSort            (void *arr_ptr[], int n_elements, int (*cmp_ptr) (const void *, const void *)); //COMMENT!!!!!!!!!!
int  My_QSort (void* arr_ptr[], int begin, int end, int (*cmp_ptr) (const void *, const void *));
int My_Swap             (void *arr_ptr[], int first, int second);
int My_Strcmp_Beginning (const void *struct_1, const void *struct_2);
int My_Strcmp_Ending    (const void *struct_1, const void *struct_2);

//---------------------------------

#endif // HAMLET_H_INCLUDED
