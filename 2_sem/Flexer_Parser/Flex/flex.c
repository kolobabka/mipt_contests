#include "flex.h"

static void Inc_Size (struct lex_array_t* larr)
{
  assert (larr);

  larr->size++;

  if (larr->size * 2 > larr->capacity)
  {
    larr->capacity *= 2;
    larr->lexems = (struct lexem_t *) realloc (larr->lexems, larr->capacity * sizeof (struct lexem_t));
    assert (larr->lexems);
  }

}


struct lex_array_t lex_string (const char *str)
{
  assert (str != NULL);

  struct lex_array_t larr = { malloc (ICAP * sizeof (struct lexem_t)), ICAP, 0};
  assert (larr.lexems != NULL);

  for (int i = 0; i < strlen (str); i++)
  {
    switch (str[i]) {
      case ' ' : break;
      case '\n': break;
      case '\t': break;
      case '(' : larr.lexems[larr.size].kind  = BRACE;
                 larr.lexems[larr.size].lex.b = LBRAC;
                 Inc_Size (&larr);
                 break;
      case ')' : larr.lexems[larr.size].kind  = BRACE;
                 larr.lexems[larr.size].lex.b = RBRAC;
                 Inc_Size (&larr);
                 break;
      case '+' : larr.lexems[larr.size].kind   = OP;
                 larr.lexems[larr.size].lex.op = ADD;
                 Inc_Size (&larr);
                 break;
      case '-' : larr.lexems[larr.size].kind   = OP;
                 larr.lexems[larr.size].lex.op = SUB;
                 Inc_Size (&larr);
                 break;
      case '*' : larr.lexems[larr.size].kind   = OP;
                 larr.lexems[larr.size].lex.op = MUL;
                 Inc_Size (&larr);
                 break;
      case '/' : larr.lexems[larr.size].kind   = OP;
                 larr.lexems[larr.size].lex.op = DIV;
                 Inc_Size (&larr);
                 break;

      default  : if (isdigit (str[i]))
                 {
                  larr.lexems[larr.size].kind    = NUM;
                  assert (sscanf (str + i, "%d", &(larr.lexems[larr.size].lex.num)) == 1);
                  while (isdigit (str[i]))
                    i++;

                  i--;
                  Inc_Size (&larr);
                  break;
                 }
                 else
                 {
                   free (larr.lexems);
                   larr.lexems = NULL;
                   return larr;
                 }
    }
  }
  // TODO:
  // for each char in str
  //   if char reminds space, skip it
  //   if char reminds number, lex number
  //   if char reminds brace, lex brace
  //   if char reminds operation, lex operation
  //   otherwise free lex array, return NULL

  return larr;
}

static void print_op (enum operation_t opcode)
{
  switch (opcode) {
    case ADD: printf (" PLUS");  break;
    case SUB: printf (" MINUS"); break;
    case MUL: printf (" MUL");   break;
    case DIV: printf (" DIV");   break;

    default: assert (0 && "unknown opcode");
  }
}

static void print_brace (enum braces_t bracetype)
{
  switch (bracetype) {
    case LBRAC: printf (" LBRAC"); break;
    case RBRAC: printf (" RBRAC"); break;

    default: assert (0 && "unknown bracket");
  }
}

static void print_num (int n)
{
  printf (" NUMBER:%d", n);
}

void print_lexem(struct lexem_t lxm)
{
  switch(lxm.kind) {
    case OP:    print_op (lxm.lex.op);      break;
    case BRACE: print_brace (lxm.lex.b);    break;
    case NUM:   print_num (lxm.lex.num);    break;

    default: assert (0 && "unknown lexem");
  }
}

void dump_lexarray (struct lex_array_t pl)
{
  int i = 0;
  assert (pl.lexems != NULL);

  for (i; i < pl.size; ++i)
    print_lexem (pl.lexems[i]);
  printf("\n");
}

static int state = 0;
// Grammar:
// expr ::= mult {+, -} expr | mult
// mult ::= term {*, /} mult | term
// term ::= ( expr ) | number

struct node_t* build_syntax_tree (struct lex_array_t lexarr)
{
  struct node_t* root = NULL;
  assert (lexarr.lexems);

  root = Par_Expr (lexarr, state);

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

struct node_t* Par_Expr (struct lex_array_t lexarr, int state)
{
  printf ("%d\n", state);
  struct node_t* m = NULL;
  struct node_t* e = NULL;

  struct node_t* root = NULL;
  //printf ("par_expr\n");

  m = Par_Mult (lexarr, state);
  if (m == NULL)
    return m;

  if (lexarr.lexems[state].kind != OP || ( (lexarr.lexems[state].kind == OP) && (lexarr.lexems[state].lex.op != ADD && lexarr.lexems[state].lex.op != SUB)))
  {
    m->data.k = OP;
    if (lexarr.lexems[state].lex.op == ADD)
      m->data.u.op = ADD;
    else
      m->data.u.op = SUB;

    state++;
    return m;
  }

  e = Par_Expr (lexarr, state);
  if (e == NULL)
    return e;

  root = (struct node_t*) calloc (1, sizeof (struct node_t));
  assert (root);

  root->left = m;
  root->right = e;
  m->parent = root;
  e->parent = root;


  return root;
}

struct node_t* Par_Mult (struct lex_array_t lexarr, int state)
{
  printf ("%d\n", state);
  struct node_t* m = NULL;
  struct node_t* e = NULL;
  //printf ("par_mult\n");

  struct node_t* root = NULL;

  m = Par_Term (lexarr, state);
  if (m == NULL)
    return m;

  if (lexarr.lexems[state].kind != OP || ( (lexarr.lexems[state].kind == OP) && (lexarr.lexems[state].lex.op != MUL && lexarr.lexems[state].lex.op != DIV)))
  {
    m->data.k = OP;
    if (lexarr.lexems[state].lex.op == MUL)
      m->data.u.op = MUL;
    else
      m->data.u.op = DIV;

    state++;
    return m;
  }

  e = Par_Mult (lexarr, state);
  if (e == NULL)
    return e;

  root = (struct node_t*) calloc (1, sizeof (struct node_t));
  assert (root);

  root->left = m;
  root->right = e;
  m->parent = root;
  e->parent = root;


  return root;
}

struct node_t* Par_Term (struct lex_array_t lexarr, int state)
{
  printf ("%d\n", state);
  struct node_t* node = NULL;
  //printf ("par_term\n");
  if (lexarr.lexems[state].kind == BRACE && lexarr.lexems[state].lex.b == LBRAC)
  {
    state++;
    node = Par_Expr (lexarr, state);
  }
  else
  {
    if (lexarr.lexems[state].kind == NUM)
    {
      node = (struct node_t*) calloc (1, sizeof (struct node_t));
      assert (node);

      node->data.k = NODE_VAL;
      node->data.u.d = NUM;
      state++;

      return node;
    }
    else
    {
      return NULL;
    }
  }


  return node;
}

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

  if (larr.lexems == NULL) {
    printf("ERROR\n");
    return 0;
  }

  //dump_lexarray (larr);

  stree = build_syntax_tree (larr);

  //result = calc_result (stree);

  //printf ("%d\n", result);

  //free_syntax_tree (stree);
  free(larr.lexems);
  return 0;
}
