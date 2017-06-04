#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
  char *acronym;
  char *translation;
  struct node *next;
}Node, *NodePtr;
NodePtr Insert_table(char *acronym, char *translation, NodePtr *hash, int n);
NodePtr search(char *acronym, NodePtr *hash, int n);
NodePtr makeNode(char * acronym, char * translastion);
int hash_function(int inKey, int n);
int ConvertToNumber(char *acronym);
