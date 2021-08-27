#include "tree.h"
//----------------------------------------
//----------------------------------------
void TheStartMenu () {

  
  printf ("####################\t\t\t\tAVL-Tree. Version 1.0.0\n\n\n");

  printf ("##########\t\tHello! Use this structure of data for yours purposes\n"
          "##########\t\tBelow you would find a help-list to use it correctly\n"
          "##########\t\tPlease, follow all the instructions\n\n");  

  HelpList ();      
  ReadCommand ();

}
//----------------------------------------
//----------------------------------------
void HelpList () {

    printf ("#####\t\t\t\tHelp-list\n\n");

    printf ("#####\t\tEnter \"start\" to begin work with a tree\n");
    printf ("#####\t\tEnter \"insert\" <key> <number> <number> <string> to insert your data\n");
    printf ("#####\t\tEnter \"find\" <key> to find data with a such key\n");
    printf ("#####\t\tEnter \"delete\" <key> to delete data with a such key from the tree\n");
    printf ("#####\t\tEnter \"dumpinrange\" <little key> <great key> to print all data with keys from little key to great key\n");
    printf ("#####\t\tEnter \"neargreatfind\" <key> to print data with the key nearest greater to entered\n");
    printf ("#####\t\tEnter \"escape\" to finish the program\n");
    printf ("#####\t\tType \"help\" for help ^_^\n"); 
}
//----------------------------------------
//----------------------------------------
void ReadCommand () {

    Tree* root = NULL;
    Tree* tmp  = NULL;
    char buffer[1024] = {};
    int sym = 0;
    char res = 0;
    
    while (res != ESCAPE) {

        printf ("Enter a command: ");
        scanf ("%s", buffer);
        res = CommandRecognizer (buffer);

        switch (res)  {

        case INSERT:
        root = InsertPars (root);
        break;
        case FIND:
        tmp = FindElem (root, 23);
        case ESCAPE:
        DeleteTree (root);
        printf ("Goodbay!!!\n");
        return;
        default:
        break;
        }
    }
}
//----------------------------------------
//----------------------------------------
char CommandRecognizer (char buffer[1024]) {

    char result = 0;

    switch (buffer[0]) {

    case 'i':
        result = strcmp (buffer, "insert");
        if (result == 0)
        return INSERT;
        else
        break;   
    case 'f':
        result = strcmp (buffer, "find");
        if (result == 0)
        return FIND;
        else
        break;  
    case 'd':
        result = strcmp (buffer, "delete");
        if (result == 0)
        return DELETE;
        result = strcmp (buffer, "dumpinrange");
        if (result == 0)
        return DUMP;
        else
        break;
    case 'n':
        result = strcmp (buffer, "neargreatfind");
        if (result == 0)
        return NEAR;
        else
        break;    
    case 'h':
        result = strcmp (buffer, "help");
        if (result == 0)
        return HELP;
        else
        break;     
    case 'e':
        result = strcmp (buffer, "escape");
        if (result == 0)
        return ESCAPE;
        else
        break;     
    default:
        break;
    }

    printf ("UNKNOWN COMMAND!!!\nPlease, try again\n");
}
//----------------------------------------
//----------------------------------------
Tree* InsertPars (Tree* root) {

    KeyType  key     = 0;
    InfoType value_1 = 0.0; 
    InfoType value_2 = 0.0;
    String*  value_3 = NULL;

    value_3 = (String*) calloc (1, sizeof (String));
    if (value_3 == NULL) {

        printf ("NO MEMORY! ATTENTION!\n");
        exit (1);
    }

    printf ("Enter a key: ");
    scanf ("%u", &key);

    printf ("Enter two numbers: ");
    scanf ("%lg", &value_1);
    scanf ("%lg\n", &value_2);

    value_3->string = (char*) calloc (64, sizeof (char)); 
    if (value_3->string == NULL) {

        printf ("NO MEMORY! ATTENTION!\n");
        exit (1);
    }

    value_3->size = 64;

    printf ("Enter a string: "); 
    FillString (value_3);

    root = InsertIntoTree (root, key, value_1, value_2, value_3);

    return root;
}
//----------------------------------------
//----------------------------------------
void FillString (String* value_3) {

    int sym = 0;
    int lenght = 0;

    while ( (sym = getchar ()) != '\n') {

        value_3->string[lenght] = sym;
        lenght++;
        if (lenght >= value_3->size) 
        Recalloc (value_3);
    }
}
void Recalloc (String* value_3) {

    value_3->size *= 2;
    value_3->string = realloc (value_3->string, sizeof (char) * value_3->size);

    for (int i = value_3->size / 2; i < value_3->size; i++) 
        value_3->string[i] = 0;
}