#include "tree.h"

int main () {

    Root mainRoot = {};
    Tree* root = NULL;

    //root = TreeInit_t ();
    // return 0;
    //TreeInit (&mainRoot);
    

    root = InsertIntoTree (root, 50, 7, 10, 13);
    root = InsertIntoTree (root, 30, 7, 10, 13);
    root = InsertIntoTree (root, 20, 7, 10, 13);
    root = InsertIntoTree (root, 15, 7, 10, 13);
    root = InsertIntoTree (root, 0, 7, 10, 13);
    
    

    
    for (int i = 100; i < 100000; i++)
    {
        root = InsertIntoTree (root, i, 7, 10, 13);
        //printf ("root->key = %u\n", root->key);
    }
    // inorder (root);
    root = DeleteElem (root, 65630);
    printf ("root->key = %u\n", root->key);

    return 0;
}