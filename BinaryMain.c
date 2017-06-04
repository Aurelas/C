#include "BinaryTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Fill_Decision_Tree(BinaryTree* tree);
void play(BinaryTree* tree);
void print(void);
int main(int argc, char* argv[])
{
  BinaryTree * t =  initBinaryTree();

  Fill_Decision_Tree(t);
  play(t);


  Destroy_Tree(t);
  return 0;
}
 void Fill_Decision_Tree(BinaryTree* tree)
 {

  char string[99];
  printf("The major question is :Where should i eat tonight in lowell?\n");
  printf("Print the first question, in yes/no format.\n");
  scanf("\n");
  fgets(string,99,stdin);
  Add_Root(tree,string);

  printf("Print the second question, in yes/no format.\n");
  scanf("\n");
  fgets(string,99,stdin);
  Add_Child(tree->root,string);

  printf("Print the third question, in yes/no format.\n");
  scanf("\n");
  fgets(string,99,stdin);
  Add_Child(tree->root,string);

  printf("Print the fourth question, in yes/no format.\n");
  scanf("\n");
  fgets(string,99,stdin);
  Add_Child(tree->root->left,string);

  printf("Print the fifth question, in yes/no format.\n");
  scanf("\n");
  fgets(string,99,stdin);
  Add_Child(tree->root->left,string);

  printf("Print the sixth question, in yes/no format.\n");
  scanf("\n");
  fgets(string,99,stdin);
  Add_Child(tree->root->right->right,string);

  printf("Print the seventh question, in yes/no format.\n");
  scanf("\n");
  fgets(string,99,stdin);
  Add_Child(tree->root->right,string);

  printf("Print the answer to the question!\n");
  scanf("\n");
  fgets(string,99,stdin);
  Add_Child(tree->root->left->left,string);

  printf("Print the answer to the question!\n");
  scanf("\n");
  fgets(string,99,stdin);
  Add_Child(tree->root->left->left,string);

  printf("Print the answer to the question!\n");
  scanf("\n");
  fgets(string,99,stdin);
  Add_Child(tree->root->left->right,string);

  printf("Print the answer to the question!\n");
  scanf("\n");
  fgets(string,99,stdin);
  Add_Child(tree->root->left->right,string);

  printf("Print the answer to the question!\n");
  scanf("\n");
  fgets(string,99,stdin);
  Add_Child(tree->root->right->left,string);

  printf("Print the answer to the question!\n");
  scanf("\n");
  fgets(string,99,stdin);
  Add_Child(tree->root->right->left,string);

  printf("Print the answer to the question!\n");
  scanf("\n");
  fgets(string,99,stdin);
  Add_Child(tree->root->right->right,string);

  printf("Print the answer to the question!\n");
  scanf("\n");
  fgets(string,99,stdin);
  Add_Child(tree->root->right->right,string);

  


  return;
}
void play(BinaryTree* tree)
{
  BinaryNode * Current;
  char player_answer;
  printf("Choose either Yes or No for the following questions!\n");
  Current = tree->root;
  printf(" %s\n" , tree->root->data);
  scanf(" %c" , &player_answer);
  if(player_answer == 'y'|| player_answer == 'Y')
    {
      Current = tree->root->left;
  printf(" %s\n" , tree->root->left->data);
  scanf(" %c" , &player_answer);
  if(player_answer == 'y'|| player_answer == 'Y')
    {
      Current = tree->root->left->left;
      if(Is_Leaf(Current))
	{
	  printf("The answer is: %s\n" , Current->data);
	  return;
	}

    }

}
  if(player_answer == 'n'|| player_answer == 'N')
    {
Current = tree->root->right;
printf(" %s\n" , tree->root->right->data);
scanf(" %c" , &player_answer);
if(player_answer == 'n'|| player_answer == 'N')
  {
    Current = tree->root->right->right;
    if(Is_Leaf(Current))
      {
	printf("The answer is: %s\n" , Current->data);
	return;
      }

  }

}

}
  
