#include "problem_st.h"

enum {
  MAXLEN = 1024
};

int main()
{
  int res = 0;
  int result = 0;
  struct lex_array_t larr;
  struct node_t* stree = NULL;
  char inp[MAXLEN] = {0};

  res = scanf("%1023c", inp);
  assert(res == 1);

  // lex to array of lexems
  larr = lex_string(inp);
  printf ("larr.size = %d\n", larr.size);

  if (larr.lexems == NULL) {
    printf("ERROR\n");
    return 0;
  }

  //dump_lexarray (larr);

  stree = build_syntax_tree (larr);

  printf ("nice cock = %p\ndata = %d\n", stree, stree->data.u.op);
  // printf ("nice cock = %p\ndata = %d\n", stree->left->left, stree->left->right->data.u.d);
  Print_Tree (stree);
  
  //result = calc_result (stree);
  
  //printf ("%d\n", result);
  
  //free_syntax_tree (stree);
  free(larr.lexems);
  return 0;
}
