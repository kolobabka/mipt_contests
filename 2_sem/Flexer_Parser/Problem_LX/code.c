
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
  struct lex_array_t larr;
  assert(str != NULL);
  larr.capacity = ICAP;
  larr.size = 0;
  larr.lexems = malloc (ICAP * sizeof (struct lexem_t));
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
        larr.lexems[larr.size].kind  = BRACE;
        larr.lexems[larr.size].lex.b = LBRAC;
        Inc_Size (&larr);
        break;
      case ')' :
        larr.lexems[larr.size].kind  = BRACE;
        larr.lexems[larr.size].lex.b = RBRAC;
        Inc_Size (&larr);
        break;
      case '+' :
        larr.lexems[larr.size].kind   = OP;
        larr.lexems[larr.size].lex.op = ADD;
        Inc_Size (&larr);
        break;
      case '-' :
        larr.lexems[larr.size].kind   = OP;
        larr.lexems[larr.size].lex.op = SUB;
        Inc_Size (&larr);
        break;
      case '*' :
        larr.lexems[larr.size].kind   = OP;
        larr.lexems[larr.size].lex.op = MUL;
        Inc_Size (&larr);
        break;
      case '/' :
        larr.lexems[larr.size].kind   = OP;
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

enum {
  MAXLEN = 1024
};

int test_dump ()
{
  struct lexem_t lxs[5] =
  {
    {BRACE, LBRAC},
    {NUM, 2},
    {OP, MUL},
    {NUM, 2},
    {BRACE, RBRAC}
  };

  struct lex_array_t larr = {lxs, 5, 5};
  dump_lexarray (larr);

  return 0;
}

int main ()
{
  int res;
  struct lex_array_t larr = {NULL, 0, 0};
  char inp[MAXLEN] = {0};

  res = scanf ("%1023c", inp);
  assert (res == 1);

  inp[strlen (inp) - 1] = '\0';



  larr = lex_string (inp);

  if (larr.lexems == NULL)
  {
    printf("ERROR\n");
    return 0;
  }

  dump_lexarray (larr);

  free (larr.lexems);
  return 0;
}
