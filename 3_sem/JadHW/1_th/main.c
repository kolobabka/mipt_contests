#include "argv.h"
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
int main (int argc, char** argv) {

    if (argc <= 1) {

        printf ("You didn't enter any numbers!\n");
        return 0;
    }

    ResultFunction (argc, argv);

    return 0;
}