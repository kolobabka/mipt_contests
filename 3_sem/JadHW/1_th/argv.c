#include "argv.h"
//--------------------------------------------------------------------------
//--------------------------------------------------------------------------
void ResultFunction (int argc, char** argv) {

    int sum     = 0;
    int index   = 1;
    int lastNum = 0;

    for (index; index < argc; index++) {
        
        int counter =  0;
        char flag   = -1;

        if (argv[index][counter] == '-' || argv[index][counter] == '+' )
            counter++;

        while (argv[index][counter] != '\0') {

            if (isdigit (argv[index][counter]) == 0) {

                flag = -1;
                break;
            }
            flag = 0;
            sum += argv[index][counter] - 48;
            counter++;
        }

        if (flag == -1) {
            
            printf ("%s\n", argv[index]);
            continue;
        }

        lastNum = argv[index][counter - 1] - 48;

        if (sum % 3 == 0 && (lastNum == 5 || lastNum == 0)) {

            printf ("bizzbuzz\n");
            continue;
        }

        if (sum % 3 == 0) {

            printf ("bizz\n");
            continue;
        }

        if (lastNum == 5 || lastNum == 0) {

            printf ("buzz\n");
            continue;
        }

        printf ("%s\n", argv[index]);
    }

}

//--------------------------------------------------------------------------
//--------------------------------------------------------------------------


