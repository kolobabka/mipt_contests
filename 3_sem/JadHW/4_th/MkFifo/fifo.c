#include "fifo.h"
//-----------------------------------------------------------
//-----------------------------------------------------------
signed char ArgError (int argc) {

    if (argc < 2) {

        printf ("Arguments are not found!\n");
        return 1;
    }

    return 0;
} 
//-----------------------------------------------------------
//-----------------------------------------------------------
signed char PerrorCheck (int error, struct pollfd* file) {


	if (file->fd <= 0) {

		printf ("Bad file descriptor!n");
	} 

    if (error == -1) {

        switch (file->revents) {

			case POLLERR:
				printf ("Read end has been closed\n");
				return 1;
			case POLLHUP:
				printf ("Peer closed its end of the channel\n");
				return 1;
			case POLLNVAL:
				printf ("File was not opened\n");
				return 1;
		}
        return 1;
    }

	if (error == 0) {

		printf ("Time error!\n");
        return 1;
    }

    return 0;
}
//-----------------------------------------------------------
//-----------------------------------------------------------
int OpenFunction (int argc, char** argv, struct pollfd* files) {

	int error = 0;
	files = (struct pollfd*) calloc (argc, sizeof (struct pollfd));

	for (int i = 0; i < argc; i++) {

		
		error = open (argv[i + 1], O_RDONLY | O_NONBLOCK);

		files[i].fd = error;

		files[i].events = POLLIN;
		
		error = poll (files, argc, -1);
		if (PerrorCheck (error, files + i)) {
			printf ("Error!\n");
			continue;
		}
			

		printf ("The file Success!\n");
	}

	

	free (files);
	return 0;
}