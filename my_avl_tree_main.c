

#include <stdio.h>
#include <stdlib.h>
#include "my_avl_tree.h"
void test1(int number)
{
  printf("%d\n", number);
  return;
}

int main(int argc, char* argv [])
{

 
  MY_SET root = NULL;
  root =  my_set_init_default();
    
   my_set_add(root,60);
  my_set_traverse(root, test1);
  my_set_destroy(&root);
  return 0;
}
