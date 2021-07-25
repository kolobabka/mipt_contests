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

  return root;
}

int calc_result(struct node_t* top)
{
  // TODO: your code here
}

void free_syntax_tree(struct node_t* top)
{
  // TODO: your code here
}

struct node_t* Par_Expr (struct lex_array_t lexarr)
{
  // printf ("%d\n", state);
  struct node_t* m = NULL;
  struct node_t* e = NULL;

  struct node_t* root = NULL;
  // printf ("par_expr\n");

  m = Par_Mult (lexarr);
  if (m == NULL)
    return m;

  
  // printf ("\n");

  if (lexarr.lexems[state].kind != OP || ( (lexarr.lexems[state].kind == OP) && (lexarr.lexems[state].lex.op != ADD && lexarr.lexems[state].lex.op != SUB)))
  {
    //printf ("Billy\n");
    //printf ("state = %d\n", state);
    return m; 
  } 
  
  while (state < lexarr.size - 1 && lexarr.lexems[state].kind == OP && (lexarr.lexems[state].lex.op == ADD || lexarr.lexems[state].lex.op == SUB))
  {
    printf ("Ya v Vale!\n");
    print_lexem (lexarr.lexems[state]);
    printf ("\n");


    root = (struct node_t*) calloc (1, sizeof (struct node_t));
    assert (root);

    root->data.k = OP;
      if (lexarr.lexems[state].lex.op == ADD)
        root->data.u.op = ADD;
      else
        root->data.u.op = SUB;  
      
    if (state < lexarr.size - 1)
      state++;

    e = Par_Expr (lexarr);
    if (e == NULL)
    {
      //printf ("state = %d\n", state);
      return e;
    }
    Print_Node (e);
    printf ("\n");

    root->left = m;
    root->right = e;
    m->parent = root;
    e->parent = root;
    if (state < lexarr.size - 1)
      state++;
    
    m = root;
    printf ("Ya uhozhy is Vale!\n");
  }
  

  

  // printf ("state = %d\n", state);
  return m;
}

struct node_t* Par_Mult (struct lex_array_t lexarr)
{
  // printf ("%d\n", state);
  struct node_t* m = NULL;
  struct node_t* e = NULL;
  // printf ("par_mult\n");

  struct node_t* root = NULL;

  m = Par_Term (lexarr);
  if (m == NULL)
    return m;

  // printf ("Fisting Ass\n");
  // print_lexem (lexarr.lexems[state]);
  // printf ("\n");
  
  if (lexarr.lexems[state].kind != OP || ( (lexarr.lexems[state].kind == OP) && (lexarr.lexems[state].lex.op != MUL && lexarr.lexems[state].lex.op != DIV)))
  {
    // printf ("Gaaaay\n");
    return m; 
  }
  // print_lexem (lexarr.lexems[state]);
  // printf ("\nSwallow cum\n");

  root = (struct node_t*) calloc (1, sizeof (struct node_t));
  assert (root);

  root->data.k = OP;
    if (lexarr.lexems[state].lex.op == MUL)
      root->data.u.op = MUL;
    else
      root->data.u.op = DIV;  
      
  if (state < lexarr.size - 1)
    state++;

  e = Par_Mult (lexarr);
  if (e == NULL)
    return e;


  root->left = m;
  root->right = e;
  m->parent = root;
  e->parent = root;


  return root;
}

struct node_t* Par_Term (struct lex_array_t lexarr)
{
  // printf ("%d\n", state);
  struct node_t* node = NULL;
  // printf ("par_term\n");
  if (lexarr.lexems[state].kind == BRACE && lexarr.lexems[state].lex.b == LBRAC || lexarr.lexems[state].lex.b == RBRAC)
  {
    if (state < lexarr.size - 1)
      state++;
    // printf ("A zdes byl???\n");
    node = Par_Expr (lexarr); 
    // if (lexarr.lexems[state].lex.b == RBRAC)
    //   state++;
  }
  else
  {
    
    if (lexarr.lexems[state].kind == NUM)
    {
      node = (struct node_t*) calloc (1, sizeof (struct node_t));
      assert (node);

      node->data.k = NODE_VAL;
      node->data.u.d = lexarr.lexems[state].lex.num;
      if (state < lexarr.size - 1)
        state++;
      // printf ("oh, shit, I'm sorry\n");
      return node;
    }
    else
    {
      
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

  //Print_Node (top);
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

// struct node_t* calc_result (struct node_t* top)
// {
//   assert (top);


//   while (top->left)
//     top = top->left;
  
//   while (top->parent)
//   {
//     top = top->parent;
//     if (top->data.k == 0)
//     {
//       switch (top->data.u.op)
//       {
//         case 0:   printf ("+ "); break;
//         case 1:   printf ("- "); break;
//         case 2:   printf ("* "); break;
//         case 3:   printf ("/ "); break;
//         default:
//           break;
//       } 
//     }
//   } 
  
// }