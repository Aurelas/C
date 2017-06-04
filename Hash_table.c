#include "HashHeader.h"


NodePtr hash[11];
int ConvertToNumber(char *acronym)
{
  int j = 0, keyNum = 0, w = 3;
  
  while(acronym[j] != '\0')
    {
      
      keyNum += w * acronym[j++];
      w = w + 2;
    }
  return keyNum;

}
int hash_function(int inKey, int n)
{
  return (inKey % (n + 1));
}
NodePtr makeNode(char * acronym, char * translastion)
{
  NodePtr  node;
  if((node = (NodePtr)malloc(sizeof(Node))) == NULL)
    {
      fprintf(stderr,"Out of memory!\n");
      exit(1);
    }
  node->acronym = acronym;
  node->translation = translastion;
  node->next = NULL;
  return node;

}
NodePtr search(char *acronym, NodePtr *hash, int n)
{
  int inKey, k;
  int compare = -1;
  int CurrinKey;
  NodePtr curr;

  inKey = ConvertToNumber(acronym);
  k = hash_function(inKey,n);
  curr = hash[k];
  if(curr == NULL)
    {
      return NULL;
    }
  CurrinKey = ConvertToNumber(curr->acronym);
  compare = strcmp(acronym,curr->acronym);
  while(curr != NULL && inKey > CurrinKey && compare != 0)
    {
      curr = curr->next;
      if(curr == NULL)
	{
	  break;
	}
      CurrinKey = ConvertToNumber(curr->acronym);
      compare = strcmp(acronym,curr->acronym);

    }
  if(compare == 0)
    {
      return curr;
    }
  else
    {
      return NULL;
    }

}
NodePtr Insert_table(char *acronym, char *translation, NodePtr *hash, int n)
{
  int inKey, k;
  int CurrinKey;
  NodePtr curr,prev,np;
  int compare;

  inKey = ConvertToNumber(acronym);
  k = hash_function(inKey, n);
  curr = hash[k];
  prev = NULL;
  if(curr == NULL)
    {
      
      np = makeNode(acronym,translation);
      hash[k] = np;
     
      return np;
      
    }
  else
    {
      
      CurrinKey = ConvertToNumber(curr->acronym);
      
      compare = strcmp(acronym,curr->acronym);
    }
  
  while(curr != NULL && inKey > CurrinKey && compare != 0)
    {
      
      prev = curr;
      curr = curr->next;
      if(curr == NULL)
	{
	  
	  break;
	}
      
      CurrinKey = ConvertToNumber(curr->acronym);
      printf("Hello\n");
      compare = strcmp(acronym,curr->acronym);
     
      if(compare == 0)
	{
	  printf("acronym already exists\n");
	  return curr;
	}
      else if(curr == NULL || inKey <= CurrinKey)
	{
	  np = makeNode(acronym,translation);
	  np->next = curr;
	  prev->next = np;
	  

	}
    
    }
  return np;
 }
