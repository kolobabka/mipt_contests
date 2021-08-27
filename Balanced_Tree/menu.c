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
    printf ("#####\t\tType \"help\" for help ^_^\n\n"); 
}
//----------------------------------------
//----------------------------------------
void ReadCommand () {

    KeyType greatKey = 0;
    Tree* root = NULL;
    Tree* tmp  = NULL;
    char buffer[1024] = {};
    int sym = 0;
    char res = 0;
    
    while (res != ESCAPE) {

        printf ("Enter a command:\n");
        scanf ("%s", buffer);
        res = CommandRecognizer (buffer);

        switch (res)  {

        case INSERT:
            root = InsertPars (root, &greatKey);
            break;
        case FIND:
            FindElemPars (root);
            break;
        case DELETE:
            root = DeleteElemPars (root);
            break;
        case DUMP:
            DumpInRangePars (root);
            break;
        case NEAR:
            NearGreat (root, greatKey);
            break;
        case ESCAPE:
            DeleteTree (root);
            printf ("Goodbay!!!\n");
            return;
        case HELP:
            HelpList ();
            break;
        default:
            printf ("UNKNOWN ERROR!\n");
            return;
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
Tree* InsertPars (Tree* root, KeyType* greatKey) {

    KeyType  key     = 0;
    InfoType value_1 = 0.0; 
    InfoType value_2 = 0.0;
    String*  value_3 = NULL;

    value_3 = (String*) calloc (1, sizeof (String));
    if (value_3 == NULL) {

        printf ("NO MEMORY! ATTENTION!\n");
        exit (1);
    }

    printf ("  Enter a key:\n");
    scanf ("%u", &key);

    if (key > *greatKey)
        *greatKey = key;

    printf ("  Enter two numbers:\n");
    scanf ("%lg", &value_1);
    scanf ("%lg", &value_2);

    value_3->string = (char*) calloc (64, sizeof (char)); 
    if (value_3->string == NULL) {

        printf ("NO MEMORY! ATTENTION!\n");
        exit (1);
    }
    fflush (stdin);

    value_3->size = 64;
    
    
    FillString (value_3);

    root = InsertIntoTree (root, key, value_1, value_2, value_3);

    return root;
}
//----------------------------------------
//----------------------------------------
void FillString (String* value_3) {

    int sym = 0;
    int lenght = 0;
    sym = getchar ();
    printf ("  Enter a string:\n"); 

    while ( (sym = getchar ()) != '\n') {

        value_3->string[lenght] = sym;
        lenght++;
        if (lenght >= value_3->size) 
        Recalloc (value_3);
    }

    printf ("\tElement is successfully added!!!\n\n");
}
//----------------------------------------
//----------------------------------------
void Recalloc (String* value_3) {

    value_3->size *= 2;
    value_3->string = realloc (value_3->string, sizeof (char) * value_3->size);

    for (int i = value_3->size / 2; i < value_3->size; i++) 
        value_3->string[i] = 0;
}
//----------------------------------------
//----------------------------------------
void FindElemPars (Tree* root) {

    unsigned int listLen = 0;
    int counter = 0;
    KeyType key = 0;
    Tree* tmp = NULL;
    printf ("  Enter a key:\n");

    scanf ("%u", &key);
    tmp = FindElem (root, key);

    root = tmp;

    while (root) {

        root = root->next;
        listLen++;
    }

    DumpList (tmp, key, listLen);
}
//----------------------------------------
//----------------------------------------
Tree* DeleteElemPars (Tree* root) {

    unsigned int listLen = 0;
    KeyType key = 0;
    Tree* tmp = NULL;
    Tree* node = NULL;
    Tree* parent = NULL;
    Tree* newTmp = NULL;
    printf ("  Enter a key of element you want to delete:\n");

    scanf ("%u", &key);
    tmp = FindElem (root, key);
    if (tmp == NULL) {

        printf ("  There is no any elements with a such key\n");
        return root;
    }
    node = tmp;

    while (node) {

        node = node->next;
        listLen++;
    }

    if (listLen > 1) {
        DumpList (tmp, key, listLen);
        printf ("\tWhat the element do you want to delete?\n");
        printf ("  Enter it's number from %d to %d:\n", 1, listLen);
        scanf  ("%u", &listLen);
    }
    else {

        root = DeleteElem (root, key);
        printf ("  The element is successfully deleted!!!\n\n");
        return root;
    }

    if (listLen == 1) {

        parent = FindParent (parent, root, key);
        newTmp = tmp->next;
        newTmp->left = tmp->left;
        newTmp->right = tmp->right;
        newTmp->difference = tmp->difference;
        newTmp->height = tmp->height;
        newTmp->prev = NULL;
        free (tmp->value_3->string);
        free (tmp->value_3);
        free (tmp);

        if (parent == NULL) {
            
            printf ("  The element is successfully deleted!!!\n\n");
            return newTmp;

        }
        else 
            if (key < parent->key) 
                parent->left  = newTmp;
            else 
                parent->right = newTmp;
    }
    else {

        for (int i = 0; i < listLen - 1; i++) 
            tmp = tmp->next;

        tmp->prev->next = tmp->next;
        if (tmp->next)
            tmp->next->prev = tmp->prev;
        
        free (tmp->value_3->string);
        free (tmp->value_3);
        free (tmp);
        printf ("  The element is successfully deleted!!!\n\n");
        return root;
    }


    printf ("  The element is successfully deleted!!!\n\n");
    return root;
}
//----------------------------------------
//----------------------------------------
void DumpList (Tree* tmp, KeyType key, unsigned int listLen) {

    int counter = 0;

    printf ("\tkey [%u]:\n", key);

    for (int i = 0; i < listLen; i++) {

        printf ("\t#%d:\n", i + 1);
        printf ("\t\tvalue #1: %lg\n", tmp->value_1);
        printf ("\t\tvalue #2: %lg\n", tmp->value_2);
        printf ("\t\tstring: ");

        while (tmp->value_3->string[counter] != '\0') {

            printf ("%c", tmp->value_3->string[counter]);
            counter++;
        }
        printf ("\n\n");
        tmp = tmp->next;
        counter = 0;
    }
}
//----------------------------------------
//----------------------------------------
void DumpInRangePars (Tree* root) {

    KeyType key1 = 0;
    KeyType key2 = 0;
    printf ("\tSet the print range with two keys\n\t"
            "{For example: print all elements inside of tree}\n\t"
            "{between 300 and 500}\n");

    printf ("  Enter two numbers:\n");
    scanf  ("%u%u", &key1, &key2);

    if (key1 > key2) {

        printf ("The first number must be smaller!");
        return;
    }

    DumpInRange (root, key1, key2);
}
//----------------------------------------
//----------------------------------------
void DumpInRange (Tree* root, KeyType key1, KeyType key2) {

    Tree* tmp  = NULL;
    Tree* node = NULL;
    unsigned listLen = 0;

    for (int counterKey = key2; counterKey >= key1; counterKey--) {

        tmp = FindElem (root, counterKey);
        if (tmp == NULL) 
            continue;
        
        node = tmp;

        while (node) {

            node = node->next;
            listLen++;
        }
        DumpList (tmp, counterKey, listLen);
        listLen = 0;    

    }    
}
void NearGreat (Tree* root, KeyType greatKey) {

    KeyType key = 0;
    Tree* tmp = NULL;

    printf (" Enter a key to find an element with the key nearest greater to entered:\n");
    scanf  ("%u", &key);

    for (unsigned counterKey = key; counterKey < greatKey; counterKey++) {

        tmp = FindElem (root, counterKey);
        if (tmp != NULL) {

            DumpInRange (root, counterKey, counterKey);
            return;
        }
    }

    if (tmp == NULL) 
        printf ("\tThere are no such elements here\n\n");

 }