#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
//..............................................................................
//..............................................................................
#define POISON -666
//..............................................................................
//..............................................................................
typedef struct command {

  char com[16];
  int num;
  int com_code;

} Command;
//..............................................................................
//..............................................................................
typedef struct request {

  int len;
  Command* reqs;

} Request;
//..............................................................................
//..............................................................................
typedef struct heap {

  int num;

} Heap;
//..............................................................................
//..............................................................................
typedef struct vector {

  int size;
  int capacity;
  Heap** arr;

} Vector;
//..............................................................................
//..............................................................................
void Req_Executer (Request* Req, Vector* vector);
void Free (Request* Req, Vector* vector);
Vector* Heap_Construct (int num_nodes);
void Insert (int num, Vector* vector);
void Extract_Max (Vector* vector);
Request* Request_Construct ();
int Req_Reader (Request* Req);
void Sift (Vector* vector);
//..............................................................................
//..............................................................................
int main ()
{
  int num_nodes = 0;
  Request* Req = NULL;
  Vector* vector = NULL;

  Req = Request_Construct ();
  num_nodes = Req_Reader (Req);
  vector = Heap_Construct (num_nodes);

  Req_Executer (Req, vector);
  Free (Req, vector);

}
//..............................................................................
//..............................................................................
Request* Request_Construct ()
{
  Request* Req = NULL;
  int check = 0;

  Req = (Request*) calloc (1, sizeof (Request));
  assert (Req);

  check = scanf ("%d", &(Req->len));
  assert (check == 1);

  Req->reqs = (Command*) calloc (Req->len, sizeof (Command));
  assert (Req->reqs);

  return Req;
}
//..............................................................................
//..............................................................................
int Req_Reader (Request* Req)
{
  assert (Req);

  int num_nodes = 0;

  for (int i = 0; i < Req->len; i++)
  {
    scanf ("%s", (Req->reqs)[i].com);

    if (strlen ((Req->reqs)[i].com) == 6)
    {
      scanf ("%d", &((Req->reqs)[i].num));
      (Req->reqs)[i].com_code = 0;
      num_nodes++;
    }
    else
      (Req->reqs)[i].com_code = 1;
  }

  return num_nodes;
}
//..............................................................................
//..............................................................................
void Req_Executer (Request* Req, Vector* vector)
{
  assert (Req);

  for (int i = 0; i < Req->len; i++)
  {
    if ( (Req->reqs)[i].com_code == 0 )
    {
      Insert ((Req->reqs)[i].num, vector);
    }
    else
      Extract_Max (vector);
  }
}
//..............................................................................
//..............................................................................
void Insert (int num, Vector* vector)
{
  assert (vector);

  (vector->arr)[vector->size]->num = num;
  vector->size++;

  Sift (vector);
}
//..............................................................................
//..............................................................................
Vector* Heap_Construct (int num_nodes)
{
  Vector* vector = NULL;

  vector = (Vector*) calloc (1, sizeof (Vector));
  assert (vector);

  vector->arr = (Heap**) calloc (num_nodes, sizeof (Heap*));
  assert (vector->arr);

  for (int i = 0; i < num_nodes; i++)
  {
    (vector->arr)[i] = (Heap*) calloc (1, sizeof (Heap));
    assert ((vector->arr)[i]);
  }
  vector->capacity = num_nodes;

  return vector;
}
//..............................................................................
//..............................................................................
void Free (Request* Req, Vector* vector)
{
  free (Req->reqs);
  free (Req);

  for (int i = 0; i < vector->capacity; i++)
    free ((vector->arr)[i]);

  free (vector->arr);
  free (vector);

}
//..............................................................................
//..............................................................................
void Sift (Vector* vector)
{
  assert (vector);
  int tmp = 0, index = 0;
  index = vector->size - 1;

  while ((vector->arr)[index]->num > (vector->arr)[ (index) / 2]->num)
  {
    tmp = (vector->arr)[ (index) / 2]->num;
    (vector->arr)[ (index) / 2]->num = (vector->arr)[index]->num;
    (vector->arr)[index]->num = tmp;

    index = index / 2;
  }
}
//..............................................................................
//..............................................................................
void Extract_Max (Vector* vector)
{
  assert (vector);

  int index = vector->size - 1;
  int tmp = 0;

  printf("%d\n", vector->arr[0]->num);

  vector->arr[0]->num = vector->arr[index]->num;

  index = 0;

  while ( ((index * 2 + 1) < vector->size) && (vector->arr[index]->num < vector->arr[index * 2]->num || vector->arr[index]->num < vector->arr[(index * 2) + 1]->num) )
  {
    if (vector->arr[index * 2]->num > vector->arr[(index * 2) + 1]->num)
    {
      tmp = (vector->arr)[index * 2]->num;
      (vector->arr)[index * 2]->num = (vector->arr)[index]->num;
      (vector->arr)[index]->num = tmp;
      index = index * 2;
    }
    else
    {
      tmp = (vector->arr)[(index * 2) + 1]->num;
      (vector->arr)[ (index * 2) + 1]->num = (vector->arr)[index]->num;
      (vector->arr)[index]->num = tmp;
      index = index * 2 + 1;
    }
  }
  vector->arr[vector->size - 1]->num = POISON;
  vector->size--;
}
