#include "problem_st.h"

int state = 0;
// Grammar:
// expr ::= mult {+, -} expr | mult
// mult ::= term {*, /} mult | term
// term ::= ( expr ) | number

struct node_t* build_syntax_tree (struct lex_array_t lexarr)
{
  struct node_t* root = NULL;
  assert (lexarr.lexems);

  root = Par_Expr (lexarr);

  if (state != lexarr.size)
  {
	//printf("THIS IS NOT THE END! cur state is = %d !\n", state);
    free (root);
	  return NULL;	
  }
  return root;
}

int calc_result(struct node_t* top)
{
  int left = 0;
  int right = 0;
  int res = 0;

  if (top->data.k == NODE_VAL)
    return top->data.u.d;
  
  left = calc_result (top->left);  
  right = calc_result (top->right);

  switch (top->data.u.op) 
  {
    case ADD: res = left + right; break;
    case SUB: res = left - right; break;
    case MUL: res = left * right; break;
    case DIV: res = left / right; break;
  }  

  return res;
}

void free_syntax_tree(struct node_t* top)
{
  if (top == NULL)
    return;
    
  if (top->left)
    free_syntax_tree (top->left);
  if (top->right)
    free_syntax_tree (top->right);

  free (top);
}

struct node_t* Par_Expr (struct lex_array_t lexarr)
{
  struct node_t* m = NULL;
  struct node_t* e = NULL;

  struct node_t* root = NULL;
  

  m = Par_Mult (lexarr);
  
  if (m == NULL)
    return m;

  if (state >= lexarr.size - 1)
    return m;

  if (state < lexarr.size - 1 && lexarr.lexems[state].kind != OP || ( (lexarr.lexems[state].kind == OP) && (lexarr.lexems[state].lex.op != ADD && lexarr.lexems[state].lex.op != SUB)))
    return m; 
   
  
  while (state < lexarr.size - 1 && lexarr.lexems[state].kind == OP && (lexarr.lexems[state].lex.op == ADD || lexarr.lexems[state].lex.op == SUB))
  {

    root = (struct node_t*) calloc (1, sizeof (struct node_t));
    assert (root);

    root->data.k = OP;
      if (state < lexarr.size - 1 && lexarr.lexems[state].lex.op == ADD)
        root->data.u.op = ADD;
      else
        root->data.u.op = SUB;  
      
    if (state < lexarr.size - 1)
      state++;

    e = Par_Mult (lexarr);
	  
    if (e == NULL)
    {
      free_syntax_tree (root);
      free_syntax_tree (m);
      return e;
    }

    root->left = m;
    root->right = e;
    
    m = root;
	
  }

  return m;
}

struct node_t* Par_Mult (struct lex_array_t lexarr)
{
  struct node_t* m = NULL;
  struct node_t* e = NULL;

  struct node_t* root = NULL;

  m = Par_Term (lexarr);
  if (m == NULL)
    return m;

  if (state >= lexarr.size - 1)
    return m;

  if (state < lexarr.size - 1 && lexarr.lexems[state].kind != OP || ( (lexarr.lexems[state].kind == OP) && (lexarr.lexems[state].lex.op != MUL && lexarr.lexems[state].lex.op != DIV)))
    return m; 

  while (state < lexarr.size - 1 && lexarr.lexems[state].kind == OP && (lexarr.lexems[state].lex.op == MUL || lexarr.lexems[state].lex.op == DIV))
  {
    root = (struct node_t*) calloc (1, sizeof (struct node_t));
    assert (root);

    root->data.k = OP;
      if (lexarr.lexems[state].lex.op == MUL)
        root->data.u.op = MUL;
      else
        root->data.u.op = DIV;  
      
    if (state < lexarr.size - 1)
      state++;

    e = Par_Term (lexarr);

    if (e == NULL)
    {
      free_syntax_tree (root);
      free_syntax_tree (m);
      return e;
    }

    root->left = m;
    root->right = e;
    
    m = root;
	
  }

  return root;
}

struct node_t* Par_Term (struct lex_array_t lexarr)
{
  struct node_t* node = NULL;

  if (state > lexarr.size - 1)
    return node;
  
  if (lexarr.lexems[state].kind == BRACE && lexarr.lexems[state].lex.b == LBRAC)
  {
    if (state <= lexarr.size - 1)
      state++;

    node = Par_Expr (lexarr); 

    if (node == NULL)
      return node;
      
    if (lexarr.lexems[state].lex.b == RBRAC)
        state++;
	  else
    {
      free_syntax_tree (node);
		  return NULL;
    }
  }
  else
  {
    
    if (lexarr.lexems[state].kind == NUM)
    {
      node = (struct node_t*) calloc (1, sizeof (struct node_t));
      assert (node);

      node->data.k = NODE_VAL;
      node->data.u.d = lexarr.lexems[state].lex.num;
      if (state <= lexarr.size - 1)
        state++;

      return node;
    }
    else
    {
      free_syntax_tree (node);
      return NULL;
    }
  }

  return node;
}

void Print_Tree (struct node_t* top)
{
  assert (top);

  if (top->left)
    Print_Tree (top->left);

  Print_Node (top);

  if (top->right)
    Print_Tree (top->right);

}

void Print_Node (struct node_t* node)
{
  if (node->data.k == 0)
  {
    switch (node->data.u.op)
    {
    case 0:   printf ("+ "); break;
    case 1:   printf ("- "); break;
    case 2:   printf ("* "); break;
    case 3:   printf ("/ "); break;
    default:
      break;
    }
  }
  if (node->data.k == 1)
    printf ("%d ", node->data.u.d);
}