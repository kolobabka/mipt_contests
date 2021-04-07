#include <stdio.h>

#include "bin_trees.h"

int main ()
{
  struct BTree_t *n1, *n2, *n3, *top;

  n2 = create_node(-1, NULL, NULL);
  n1 = create_node(0, n2, NULL);
  n3 = create_node(1,NULL,NULL);

  top = create_node (7, n1, n3);

  print_edge (top);

  free_tree (top);

};
