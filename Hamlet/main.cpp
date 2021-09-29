#include "Hamlet.h"

FILE *LOG_FILE = NULL;

int main (int argc, char *argv[])
{
    if (Open_Logfile () == ERROR)
        return EXIT_FAILURE;

    struct Basic_Data hamlet
    {
        NULL,
        "hamlet.txt",
        "sorted.txt",
        NULL,
        NULL,
        NULL,
        0L,
        0
    };

    MY_ASSERT (Run_Hamlet (&hamlet) == NO_ERRORS, "Run_Hamlet ()", "An error somewhere in the program");

    Close_File (LOG_FILE, "log_file.log");

    return 0;
}
