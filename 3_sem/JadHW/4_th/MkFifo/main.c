#include "fifo.h" 

int main (int argc, char** argv) {

    struct pollfd* files = NULL;
    int result = 0;
    
    if (ArgError (argc)) 
        return -1;

    result =  OpenFunction (argc - 1, argv, files);

    if (result)
        return -1;
    
    return 0;
}