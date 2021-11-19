#include "cane.h"

int main (int argc, char** argv) {

    int file_1 = 0;
    int file_2 = 0;
    int err = 0;

    if (ArgError (argc, argv) == 0) 
        return -1;

    file_1 = open (argv[1], O_RDONLY);
    if (PerrorCheck (file_1))
        return -1;

    if (CaneImmitation (file_1, argv[1]))
        return -1;

    close (file_1);
    return 0;
}