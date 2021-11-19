#include "cane.h"
//-----------------------------------------------------------
//-----------------------------------------------------------
static long long SizeText (char* const textName)
{

    struct stat size;
 	stat (textName, &size);

    return (long long) size.st_size;
}
//-----------------------------------------------------------
//-----------------------------------------------------------
static void SkipTrash (char** buffer) {

    assert (buffer);

    while (isspace (**buffer)) 
        ++(*buffer);
}
//-----------------------------------------------------------
//-----------------------------------------------------------
static void Delete (Command* commandsArr, const long commandsNum) {

    for (long index = 0; index < commandsNum; ++index)
        free (commandsArr[index].argv);

    free (commandsArr);

}
//-----------------------------------------------------------
//-----------------------------------------------------------
static char** HandleArgv (char* buffer, const int argc) {

    char** argv = (char**)calloc (argc + 1, sizeof (*argv));

    int curArgvInd = 0;
    argv [curArgvInd++] = buffer;
    
    char* nextWord = NULL;
    while ((nextWord = strchr (buffer, ' ')) && curArgvInd < argc) {
    
        char* toReplace = nextWord;
        SkipTrash (&nextWord);
        *toReplace = 0;

        argv [curArgvInd++] = nextWord;

        buffer = nextWord;
    
    }

    for (int curArg = 0; curArg < argc; curArg++) { //to set '\0' at the end of string
    
        char* curArgStr = argv [curArg];

        size_t curSymb = 0;
        for (; !isspace (curArgStr [curSymb]) && curArgStr [curSymb] != 0; curSymb++) {}
    
        curArgStr [curSymb] = 0;

    }

    argv [argc] = NULL;

    return argv;

}
//-----------------------------------------------------------
//-----------------------------------------------------------
int CaneImmitation (int file_1, char* const textName) {

    assert (textName);
    int error = 0;
    long long sizeOfFile = SizeText (textName);    
    char* buffer = (char*) calloc (sizeOfFile + 1, sizeof (char));
    assert (buffer && "Lack of memory! Attention!");

    error = read (file_1, buffer, sizeOfFile);

    close (file_1);
    if (PerrorCheck (error))
        return -1;
    
    Command* commands = CommandRecognizer (buffer, sizeOfFile);
    if (commands == NULL)
        return -1;
    free (buffer);
}
//-----------------------------------------------------------
//-----------------------------------------------------------
Command* CommandRecognizer (char* buffer, long long sizeOfFile) {

    assert (buffer);
    long index = 0;
    long numCommands = 0;

    numCommands = CommandCounter (buffer);

    Command* commands = (Command*) calloc (numCommands, sizeof (Command));
    assert (commands);

    SeparateCommands (commands, buffer);
    if (Execution (commands, numCommands))
        return NULL;

    Delete (commands, numCommands);
    
}
//-----------------------------------------------------------
//-----------------------------------------------------------
long CommandCounter (char* buffer) {

    assert (buffer);
    long index = 0;
    long numCommands = 1;

    while (buffer[index]) 
        if (buffer[index++] == '|')  
            ++numCommands;

    return numCommands;
}
//-----------------------------------------------------------
//-----------------------------------------------------------
void SeparateCommands (Command* commands, char* buffer) {

    assert (commands);
    assert (buffer);

    long index = 0;

    char* curCommand = NULL;

    curCommand = strtok (buffer, "|");

    while (curCommand) {
    
        SkipTrash (&curCommand);

        commands[index].argc = argcCounter (curCommand);
        commands[index].argv = HandleArgv (curCommand, commands[index].argc);
        assert (commands[index].argv);

        curCommand = strtok (NULL, "|");

        ++index;
    } 
}
//-----------------------------------------------------------
//-----------------------------------------------------------
int argcCounter (char* curCommand) {

    assert (curCommand);
    int index = 0;
    int numArgc = 0;

    while (*curCommand) {
        if (isspace (*curCommand)) {

            ++numArgc;
            SkipTrash (&curCommand);
        }
        else 
            ++curCommand;
    }

    return numArgc;
}
//-----------------------------------------------------------
//-----------------------------------------------------------
int Execution (Command* commands, long numCommands) {

    assert (commands);
    int error = 0, waitstatus = 0;
    int* files = (int*) calloc (2 * (numCommands - 1), sizeof (int));
    pid_t pid, chpid;
    for (int index = 0; index < numCommands - 1; ++index) {

        error = pipe (files + 2 * index);
        if (PerrorCheck (error))
            return -1;
    }

    for (int index = 0; index < numCommands; ++index) {

        pid = fork ();
        if (PerrorCheck (pid))
            return -1;

        if (pid == 0) {

            if (index != 0) {

                error = dup2 (files[2 * (index - 1)], STDIN_FILENO);
                if (PerrorCheck (error))
                    return -1;
            }
            if (index != numCommands - 1) {

                error = dup2 (files[2 * index + 1], STDOUT_FILENO);
                if (PerrorCheck (error))
                    return -1;
            }

            for (int counter = 0; counter < 2 * (numCommands - 1); ++counter) {

                error = close (files[counter]);
                if (PerrorCheck (error))
                    return -1;
            }

            error = execvp (commands[index].argv[0], commands[index].argv);
            if (PerrorCheck (error))
                return -1;
        }

    }

    chpid = wait (&waitstatus);
    if (PerrorCheck (waitstatus))
        return -1;

    free (files); 
    return 0;
}