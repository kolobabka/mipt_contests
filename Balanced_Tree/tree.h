#pragma once
//----------------------------------------
//----------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//----------------------------------------
//----------------------------------------
#define IS_NULL(ptr)    !ptr
//----------------------------------------
//----------------------------------------
typedef unsigned int KeyType; //Use type "KeyType" instead of the basic type "unsigned int"
typedef double       InfoType;
typedef int          Balance;
//----------------------------------------
//----------------------------------------
// Declarations of structers and enums
typedef enum TreeErrors {

    NULL_POINTER_ON_TREE,
    NO_TREE_ERR

}   TreeErrors;

//----------------------------------------
//----------------------------------------
enum Commands {

  INSERT,
  FIND,
  DELETE,
  DUMP,
  NEAR,
  HELP,
  ESCAPE
};
//----------------------------------------
//----------------------------------------
//----------------------------------------
//----------------------------------------
typedef struct String {

  char* string;
  int size;

} String;
//----------------------------------------
//----------------------------------------
typedef struct Tree {

    Balance       difference;
    int           height;
  // Key field
    KeyType        key;
  // Address fields  
    struct Tree*  left;
    struct Tree*  right;

    struct Tree*  next;
    struct Tree*  prev;
  // Informational fields 
    InfoType      value_1;
    InfoType      value_2;
    String*       value_3;

} Tree;
//----------------------------------------
//----------------------------------------
typedef struct Root {

  // Root of the tree 
    Tree* root;
    char  isRootFull;
    
} Root;
//----------------------------------------
//----------------------------------------
//Prototypes of functions
static char CompareData (Tree* root, InfoType value_1, InfoType value_2, String* value_3);
Tree* InsertIntoTree (Tree* mainRoot, KeyType key, InfoType value_1, InfoType value_2, String* value_3);
Tree* RotateLeft (Tree* balanceNode);
void PrintTreeErr (TreeErrors err);
TreeErrors FixHeight (Tree* node);
Tree* TreeBalance (Tree* node);
Tree* RotateRight (Tree* node);
int Difference (Tree* node);
Tree* FindMin (Tree* node);
Tree* DeleteMinElen (Tree* node);
Tree* DeleteElem (Tree* node, KeyType key);
Tree* FindElem (Tree* root, KeyType key);
void DeleteTree (Tree* root);
void TheStartMenu ();
void HelpList ();
char CommandRecognizer (char buffer[1024]);
void FindElemPars (Tree* root);
void Recalloc (String* value_3);
void FillString (String* value_3);
Tree* InsertPars (Tree* root, KeyType* greatKey);
void ReadCommand ();
Tree* DeleteElemPars (Tree* root);
void DumpList (Tree* tmp, KeyType key, unsigned int listLen);
Tree* FindParent (Tree* parent, Tree* node, KeyType key);
void DumpInRangePars (Tree* root);
void DumpInRange (Tree* root, KeyType key1, KeyType key2);
void NearGreat (Tree* root, KeyType greatKey);