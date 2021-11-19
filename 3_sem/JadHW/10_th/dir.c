#include <sys/types.h>
#include <dirent.h>
#include "dir.h"

typedef DIR BRIGADIR;

struct dirent *readdir(BRIGADIR *dirp);
BRIGADIR      *opendir(const char *name);
BRIGADIR      *fdopendir(int fd);

int closedir(DIR *dirp);

int main (int argc, char** argv) {

    // if (ArgError (argc, argv))
    //     return -1;

    if (ReadDirs (argv[1]))
        return -1;

    return 0;
}

int ReadDirs (const char* path) {

    assert (path);

    struct dirent* folder = NULL;
    DIR* folderPtr = NULL;

    folderPtr = opendir (path);
    if (path == NULL) {
        
        perror ("Directory problem:");
        return -1;
    }
    while (folder = readdir (folderPtr)) {

        if (folder->d_type == DT_DIR)
            printf ("%s\n", folder->d_name);
    }


    int error = closedir (folderPtr);
    if (error != 0)
        perror ("Problem with close");  

    
}