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
  struct node_t* root = NULL;
  char inp[MAXLEN] = {0};

  res = scanf("%1023c", inp);
  assert(res == 1);

  // lex to array of lexems
  larr = lex_string(inp);
  printf ("larr.size = %d\n", larr.size);

  if (larr.lexems == NULL) 
  {
    printf("ERROR\n");
    return 0;
  }
  
  stree = build_syntax_tree (larr);
  if (stree == NULL)
  {
    free( larr.lexems);
    printf ("ERROR\n");
    return 0;
  }
  
  root = stree;
  
  result = calc_result (stree);
  
  printf ("ptr = %p\n", stree); 
  printf ("%d\n", result);
  
  free_syntax_tree (root);
  free( larr.lexems);
  return 0;
}
