#include <stdio.h>
#include <sys/types.h>
#include <assert.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
//..............................................................................
//..............................................................................
void StrCopy (int file1, int file2, char* text);
int ErrorCheck (int error);
//..............................................................................
//..............................................................................
int main (int argc, char** argv) {

	int file1 = 0;
	int file2 = 0;
	int size1 = 0;
	int size2 = 0;

	if (argc != 3) {

		printf ("You must input 2 files\n");
		return 0;
	}

	file1 = open (argv[1], O_RDWR);
	file2 = open (argv[2], O_RDWR | O_CREAT, 0777);

	ErrorCheck (file1);

	ErrorCheck (file2);

 	StrCopy (file1, file2, argv[1]);

	close (file1);
	close (file2);

	return 0;
}
//..............................................................................
//..............................................................................
static int SizeText (char* const textName)
{
  assert (textName);

  struct stat size;
 	stat (textName, &size);

  return size.st_size;
}
//..............................................................................
//..............................................................................
void StrCopy (int file1, int file2, char* text) {

	char* buf1 = NULL;
	char* buf2 = NULL;
	int error = 0;
	int size1 = 0;
	size1 = SizeText (text);

	buf1 = (char*) calloc (size1 + 1, sizeof (char));
	assert (buf1);

	error = read (file1, buf1, size1);

	if (ErrorCheck (error) == -1) {

		free (buf1);
		return;
	}

	error = write (file2, buf1, size1);
	if (ErrorCheck (error) == -1) {

		free (buf1);
		return;
	}

	if (ErrorCheck (error) == -1) {

		free (buf1);
		return;
	}

	free (buf1);
}
//..............................................................................
//..............................................................................
int ErrorCheck (int error) {

	if (error == -1) {

		printf ("Error\n");
		return -1;
	}

	return 0;
}
