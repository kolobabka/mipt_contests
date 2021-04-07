#include "bintree.h"

int main ()
{
  struct BTree_t *top = NULL;
  //struct BTree_t *n,*n1, *n2, *n3, *top, *n4,*n5,*n6,*n7,*n8;

  // n4 = create_node (-5, NULL, NULL);
  // n5 = create_node (-8, NULL, NULL);
  // n7 = create_node (9, NULL, NULL);
  // n8 = create_node (13, NULL, NULL);
  // n6 = create_node (12, n7, n8);
  // n3 = create_node (-6, n5, n4);
  // n2 = create_node (-3, n3, NULL);
  // n1 = create_node (-1, n2, NULL);
  // n = create_node (0, n1, n6);

  top = read_zero_one_tree (stdin);
  print_tree (top);
  free_tree (top);


  // top->parent = NULL;
  // n->parent = top;
  // n1->parent = n;
  // n6->parent = n;
  // n2->parent = n1;
  // n3->parent = n2;
  // n4->parent = n3;
  // n5->parent = n3;
  // n7->parent = n6;
  // n8->parent = n6;



}
