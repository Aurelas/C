#include <stdlib.h>
#include <stdio.h>
#include "my_avl_tree.h"

typedef struct node Node;

struct node
{
  int data;
  Node* left;
  Node* right;
  int height;
};

struct my_set
{
  Node* root;

};

typedef struct my_set My_set;
int height_helper(Node *pRoot);
void preOrder(Node *root);
int maximum(int a, int b);
void destroy(Node* root);
void insert(Node** pRoot, int item);
void my_set_in_order_traverse(Node* root, void (*visit)(int));

MY_SET my_set_init_default()
{
  My_set *temp;
  
  temp = (My_set*)malloc(sizeof(My_set));
  if(temp != NULL)
    {
      temp->root = NULL;
    }
  return (MY_SET)temp;
}

void my_set_destroy(MY_SET* p_hMY_SET)
{
  My_set *temp = (My_set*)*p_hMY_SET;
  
  if(temp != NULL)
    {
      destroy(temp->root);
      free(temp);
    }
}

void destroy(Node* root)
{
  if(root == NULL)
    {
      return;
    }
  else
    {
      destroy(root->left);
      destroy(root->right);
      free(root);
    }
}

Boolean my_set_traverse(MY_SET hMY_SET, void (*visit)(int))
{
  My_set *temp = (My_set*)hMY_SET;
  
  if(temp != NULL)
    {
    
      my_set_in_order_traverse(temp->root, visit);
        
      return TRUE;
    }
  return FALSE;
}
void my_set_in_order_traverse(Node* root, void (*visit)(int))
{
  if(root == NULL)
    {
 
      return;
    }
  else
    {
      
      my_set_in_order_traverse(root->left, visit);
      printf("%d" ,root->left->data);
      my_set_in_order_traverse(root->right, visit);
      
      return;
    }
}
int get_balanced(Node *pRoot)
{
  if (pRoot == NULL)
    {
      return 0;
    }
  
  return (height_helper(pRoot->left) - height_helper(pRoot->right));
}
Node *leftRotate(Node *x)
{
  Node *otherNode = x;
  otherNode = x->right;
  x->right = otherNode->left;
  otherNode->left = x;

  
   
  
  // Update heights
  x->height = maximum(height_helper(x->left), height_helper(x->right))+1;
  otherNode->height = maximum(height_helper(otherNode->left), height_helper(otherNode->right))+1;
  // Return new root
  return otherNode;
}
Node *rightRotate(Node *y)
{

  Node *otherNode = y;
  otherNode = y->left;
  y->left = otherNode->right;
  otherNode->right = y;
  // Perform rotation
   
  
  // Update heights
  y->height = maximum(height_helper(y->left), height_helper(y->right))+1;
  otherNode->height = maximum(height_helper(otherNode->left), height_helper(otherNode->right))+1;

  // Return new root
  return otherNode;
}
int maximum(int a, int b)
{
  int c;
  if (a>b)
    {
      c = a;
    }
  else
    {
      c= b;
    }
  return c;
}

Boolean my_set_add(MY_SET hMY_SET, int item)
{
  My_set *temp = (My_set*) hMY_SET;
  if(temp != NULL)
    {
     
      insert(&(temp->root), item);
      return TRUE; 
    }

  return FALSE;
}
void insert(Node** pRoot, int item)
{
 
  Node* temp;
  // int balance; 
   if(*pRoot == NULL)
     {
      //allocate a node and set it up
      temp = (Node*)malloc(sizeof(Node));
      if(temp == NULL)
	{
	  printf("Memory allocation has failed\n");
	  exit(1);
	}
      temp->data = item;
      temp->left = NULL;
      temp->right = NULL;
      temp->height = 1;
      *pRoot = temp;
      return;
    }
  else
    {
      
    
       if(item < (*pRoot)->data)
	 {
	   insert(&((*pRoot)->left), item);
	 }
       else
	 {
	   insert(&((*pRoot)->right), item);
	 }
    }
  
   return;
    

}


Boolean my_set_remove(MY_SET hMY_SET, int item);

int my_set_height(MY_SET hMY_SET)
{
  My_set *temp = (My_set*)hMY_SET;

  if(temp == NULL)
    {
      return 0;
    }
  return height_helper(temp->root);
}
int height_helper(Node *pRoot)
{
  Node* temp = pRoot;
  if (pRoot == NULL)
    {
     
      return 0;
    }
  return temp->height;

}

