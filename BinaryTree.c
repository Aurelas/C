#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree.h"

int Has_Left(BinaryNode *node)
{
  if(node->left != NULL)
    {
      printf("Has left data!\n");
      return 1;
    }
  return 0;

}
int Has_Right(BinaryNode *node)
{
  if(node->right != NULL)
    {
      printf("Has right data!\n");
      return 1;
    }
  return 0;

}
int Is_Leaf(BinaryNode *node)
{
  if(node->left == NULL && node->right == NULL)
    {
      printf("Is a leaf!\n");
      return 1;
    }
  return 0;
}
BinaryTree *initBinaryTree()
{
  BinaryTree*  tree;


  if ((tree = (BinaryTree*)malloc(sizeof(BinaryTree))) == NULL)
    {
      fprintf(stderr, "Out of memory\n");
      exit(1);
    }
  tree->root = NULL;
  return tree;

}
int Is_Empty(BinaryTree * tree)
{
  if(tree->root == NULL)
    {
      printf("The tree is empty\n");
      return 0;
    }
  return 1;

}
BinaryNode * makeNode(NodeData data)
{
  BinaryNode * node;


  if ((node = (BinaryNode*)malloc(sizeof(BinaryNode))) == NULL)
    {
      fprintf(stderr, "Out of memory\n");
      exit(1);
    }


  strncpy(node->data, data, sizeof(NodeData));
  node->data[sizeof(NodeData) - 1] = '\0';


  node->left = NULL;
  node->right = NULL;


  return node;
}
BinaryNode * Add_Root(BinaryTree* tree, NodeData data)
{
  tree->root = makeNode(data);
  return tree->root;

}
BinaryNode* Add_Child(BinaryNode* node, NodeData data)
{
  BinaryNode * node2;


  node2 = makeNode(data);
  if(node->left == NULL)
    {
      node->left = node2;
      return node;
    }
  else
    {
      node->right = node2;
      return node;

    }

}
void Empty_Subtree(BinaryNode* node)
{
  if (node == NULL)
    {
      return;
    }


  Empty_Subtree(node->left);


  Empty_Subtree(node->right);


  free(node);
}
void emptyTree(BinaryTree * tree)
{

  Empty_Subtree(tree->root);
}
void Destroy_Tree(BinaryTree* tree)
{

  emptyTree(tree);
  free(tree);
}


int Num_Node_Subtree(BinaryNode* node)
{
  if (node == NULL)
    {
      return 0;
    }


  return 1 + Num_Node_Subtree(node->left) + Num_Node_Subtree(node->right);

}
int Num_Leaves_Subtree(BinaryNode* node)
{

  if (node == NULL)
    {
      return 0;
    }


  if (Is_Leaf(node))
    {
      return 1;
    }


  return Num_Leaves_Subtree(node->left) + Num_Leaves_Subtree(node->right);

}
int Height_Subtree(BinaryNode* node)
{
  int                     Left_Height;
  int                     Right_Height;


  if (node == NULL)
    {
      return 0;
    }


  Left_Height = Height_Subtree(node->left);
  Right_Height = Height_Subtree(node->right);


  return 1 + (Left_Height > Right_Height ? Left_Height : Right_Height);

}
