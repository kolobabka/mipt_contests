#include "problem_lx.h"

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

  char digit_arr[32] = {0};
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
