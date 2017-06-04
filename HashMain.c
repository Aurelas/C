#include "HashHeader.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  NodePtr c;
  NodePtr hash[10000];
  FILE * file;
  char acro[100];
  char translation[100];
  int counter = 0;
 
  file = fopen("dictionary.txt" , "r");
 if(!file)
    {
      printf("bad\n");
    }
 do{
   counter++;
   if(counter == 1 || counter == 3 || counter == 5 || counter == 7)
     {
       fscanf(file,"%s" , acro);
     }
   if(counter == 2 || counter == 4 || counter == 6 || counter == 8)
     {
      fscanf(file,"%s",translation);
     }
   Insert_table(acro,translation,hash,13);
 }while(counter < 9 );
 c = search(acro,hash,13);
 printf("%s\n" , c->acronym);
  fclose(file);
 
  return 0;
}
