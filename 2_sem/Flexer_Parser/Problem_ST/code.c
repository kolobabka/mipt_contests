#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// lexem is operation | brace | number
enum lexem_kind_t {
  OP    = 0,
  BRACE = 1,
  NUM   = 2
};

// operation is: +, -, *, /
enum operation_t {
  ADD = 0,
  SUB = 1,
  MUL = 2,
  DIV = 3
};

// braces are: (, )
enum braces_t {
  LBRAC = 0,
  RBRAC = 1
};

// lexem is one of lexem kind entities
// if (l.kind == BRACE)
//   assert(l.lex.b == LBRAC || l.lex.b == RBRAC)
struct lexem_t {
  enum lexem_kind_t kind;
  union {
    enum operation_t op;
    enum braces_t b;
    int num;
  } lex;
};

// array of lexems
// size: actual number of elements
// capacity: number of additions before realloc
struct lex_array_t {
  struct lexem_t *lexems;
  int capacity;
  int size;
};

// initial capacity
enum {
  ICAP = 10
};

// string to lexem array: see Problem LX on slides
struct lex_array_t lex_string (const char *str);

// printing
void print_lexem (struct lexem_t lxm);
void dump_lexarray (struct lex_array_t pl);

enum node_kind_t {
  NODE_OP,
  NODE_VAL
};

struct node_data_t {
  enum node_kind_t k;
  union {
    enum operation_t op;
    int d;
  } u;
};

struct node_t {
  struct node_t* left;
  struct node_t* right;
  struct node_data_t data;
};

struct node_t* build_syntax_tree (struct lex_array_t lexarr);
struct node_t* Par_Expr (struct lex_array_t lexarr);
struct node_t* Par_Mult (struct lex_array_t lexarr);
struct node_t* Par_Term (struct lex_array_t lexarr);

void Print_Node (struct node_t* node);
void Print_Tree (struct node_t* top);
int calc_result (struct node_t* top);

void free_syntax_tree (struct node_t* top);

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

  struct lex_array_t larr = { malloc (ICAP * sizeof (struct lexem_t)), ICAP, 0};
  assert(str != NULL);
  assert(larr.lexems != NULL);

  for (int i = 0; i < strlen (str); i++)
  {
    //printf("larr->size = %d\n", larr.size);
    //printf("larr->capacity = %d\n", larr.capacity);
    switch (str[i]) {
      case ' ' :
        break;
      case '\n':
        break;
      case '\t':
        break;
      case '(' :
        larr.lexems[larr.size].kind = BRACE;
        larr.lexems[larr.size].lex.b = LBRAC;
        Inc_Size (&larr);
        break;
      case ')' :
        larr.lexems[larr.size].kind = BRACE;
        larr.lexems[larr.size].lex.b = RBRAC;
        Inc_Size (&larr);
        break;
      case '+' :
        larr.lexems[larr.size].kind = OP;
        larr.lexems[larr.size].lex.op = ADD;
        Inc_Size (&larr);
        break;
      case '-' :
        larr.lexems[larr.size].kind = OP;
        larr.lexems[larr.size].lex.op = SUB;
        Inc_Size (&larr);
        break;
      case '*' :
        larr.lexems[larr.size].kind = OP;
        larr.lexems[larr.size].lex.op = MUL;
        Inc_Size (&larr);
        break;
      case '/' :
        larr.lexems[larr.size].kind = OP;
        larr.lexems[larr.size].lex.op = DIV;
        Inc_Size (&larr);
        break;

      default  :
        if (isdigit (str[i]))
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
    case ADD:
      printf (" PLUS");
      break;
    case SUB:
      printf (" MINUS");
      break;
    case MUL:
      printf (" MUL");
      break;
    case DIV:
      printf (" DIV");
      break;

    default:
      assert (0 && "unknown opcode");
  }
}

static void print_brace (enum braces_t bracetype)
{
  switch (bracetype) {
    case LBRAC:
      printf (" LBRAC");
      break;
    case RBRAC:
      printf (" RBRAC");
      break;

    default:
      assert (0 && "unknown bracket");
  }
}

static void print_num(int n)
{
  printf(" NUMBER:%d", n);
}

void print_lexem(struct lexem_t lxm)
{
  switch(lxm.kind) {
    case OP:
      print_op (lxm.lex.op);
      break;
    case BRACE:
      print_brace (lxm.lex.b);
      break;
    case NUM:
      print_num (lxm.lex.num);
      break;

    default:
      assert (0 && "unknown lexem");
  }
}

void dump_lexarray(struct lex_array_t pl)
{
  int i = 0;
  assert(pl.lexems != NULL);

  for (i; i < pl.size; ++i)
    print_lexem(pl.lexems[i]);
}

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
    free_syntax_tree (root);
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
    case ADD:
      res = left + right;
      break;
    case SUB:
      res = left - right;
      break;
    case MUL:
      res = left * right;
      break;
    case DIV:
      res = left / right;
      break;
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

    if (state <= lexarr.size - 1 && lexarr.lexems[state].lex.b == RBRAC)
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
    case 0:
      printf ("+ ");
      break;
    case 1:
      printf ("- ");
      break;
    case 2:
      printf ("* ");
      break;
    case 3:
      printf ("/ ");
      break;
    default:
      break;
    }
  }
  if (node->data.k == 1)
    printf ("%d ", node->data.u.d);
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
  struct node_t* root = NULL;
  char inp[MAXLEN] = {0};

  res = scanf("%1023c", inp);
  assert(res == 1);

  // lex to array of lexems
  larr = lex_string(inp);

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

  printf ("%d\n", result);

  free_syntax_tree (root);
  free( larr.lexems);
  return 0;
}
