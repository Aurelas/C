#include "My_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define STARTING_CAPACITY = 7;

struct my_string
{
  int size;
  int capacity;
  char* data;

};
  typedef struct my_string My_string;
MYSTRING mystring_init_default(void)
{
  My_string *string = NULL;

  string =(My_string*)malloc(sizeof(My_string));
  if(string != NULL)
    {     
      string->size = 0;
      string-> capacity = MYSTRING_STARTING_CAPACITY;
      string->data = (char*)malloc(sizeof(char)*string->capacity);
    }  
  if(string->data == NULL)
    {
      free(string->data);
      free(string);
      string = NULL;
    }
			   return (MYSTRING)string; 
}


MYSTRING mystring_init_c_string(const char * const c_string)
{
  My_string *string = NULL;
  int stringlength = 0;
  int i = 0;
  while(c_string[stringlength] != '\0')
      {
	stringlength++;
       }
  string = (My_string*)malloc(sizeof(My_string));
  if(string != NULL)
    {
      string->size = stringlength;
      string->capacity = stringlength;
      string->data = (char*)malloc(sizeof(char)*string->capacity);

    }
  if(string->data == NULL)
    {
      free(string->data);
      free(string);
      string = NULL;
    }
  for(i = 0; i < stringlength; i++)
    {
      if(c_string[i] != '\0')
	{
	  string->data[i] = c_string[i];
	}
    }
    return(MYSTRING)string; 

}
void mystring_destroy(MYSTRING* p_hString)
{
  My_string *string = (My_string*)(*p_hString);
  if(string != NULL)
    {
      free(string->data);
      free(string);
      *p_hString = NULL;
    }
}
int mystring_size(MYSTRING hString)
{
 My_string *string =(My_string*)hString;
  if(string != NULL)
    {
      return string->size; 
    }
  else
    {
      return -1;
    }
   

}
int mystring_capacity(MYSTRING hString)
{
  My_string* string = (My_string*)hString;
  if(string != NULL)
    {
      return string->capacity;
    }
  else
    {
      return -1;
    }

}
MyString_Status mystring_output(MYSTRING hString, FILE* out)
{

  My_string* string = (My_string*)hString;
  int i;
  if(string == NULL || out == NULL)
    {
      return MYSTRING_STATUS_ERROR;
    }
   for(i=0; i < string->size; i++)
    {
      fprintf(out, "%c", string->data[i]);
    }
    return MYSTRING_STATUS_SUCCESS;
}
MyString_Status mystring_concatenate_c_string(MYSTRING hString,
                                              char * c_string)
{
  My_string *string = (My_string*)hString;
  int stringlength = 0;
  char *temp;
  int i = 0;
  int data = 0;
  while(c_string[stringlength] != '\0')
    {
      stringlength++;
    }
  for(i=0; i <= string->size - 1 ; i++)
    {
      data++;
    }
  if(string->size + stringlength >= string->capacity)
    {
      string->capacity = string->size + stringlength + 1;
      temp = (char*)malloc(sizeof(char)*string->capacity);
      if(temp != NULL)
	{
	  for(i=0; i < string->size; i++)
	    {
	      temp[i] = string->data[i];
	    }
	  free(string->data);
	  string->data = temp;
	
    
	  for(i = 0; i < stringlength; i++)
	    {
	      string->data[data] = c_string[i];
	      data++;
	      string->size++;

	    }
	  return MYSTRING_STATUS_SUCCESS;
	}
    }
  return MYSTRING_STATUS_ERROR;
}

MyString_Status mystring_concatenate_mystring(MYSTRING hStringDest, MYSTRING hStringSource)
{
   My_string *string = (My_string*)hStringSource;
   My_string *new = (My_string*)hStringDest;
   char *temp;  
   int i;
   int data = 0;
   int j;


   if(hStringDest != NULL || hStringSource != NULL || string->data != NULL)
     {
       new->size = string->size + new->size;
       if(new->size >= new->capacity)
	 {
	   new->capacity = new->size + 1;
	   temp = (char*)malloc(sizeof(char)*new->capacity);
	   if(temp != NULL)
	     {

	       for(i=0;i < new->size - string->size; i++)
		 {
		   temp[i] = new->data[i];
		   data++;
		 }
	       free(new->data);
	       new->data = temp;
	       for(j=0; j < string->size; j++)
		 {
		   new->data[data + j] = string->data[j];
		   
		 }
	       return MYSTRING_STATUS_SUCCESS;
	     }
	 }
     }


   
      return MYSTRING_STATUS_ERROR;

 

}
MyString_Status mystring_truncate(MYSTRING hString, int newMaxLen)
{
  My_string *string = (My_string*)hString;
  int subtract_length;
  int i = 0;
  if(string != NULL)
    {

      subtract_length = string->size - newMaxLen;
      if(newMaxLen > string->size)
	{
	  return MYSTRING_STATUS_SUCCESS;
	}
      for(i = 0; i < subtract_length; i++)
	{
	  string->size--;
	}
      return MYSTRING_STATUS_SUCCESS;
    }
  return MYSTRING_STATUS_ERROR;

}
MyString_Status mystring_push(MYSTRING hString, char ch)
{
  My_string *string = (My_string*)hString;
  int i;
  char *temp;
  if(string != NULL)
    {

	  if(string->size >= string->capacity)
	    {
	      string->capacity *= 2;
	      temp = (char*)malloc(sizeof(char)*string->capacity);
	      if(temp != NULL)
		{
		  for(i=0; i < string->size; i++)
		    {
		      temp[i] = string->data[i];
		    }
		  free(string->data);
		  string->data = temp;
		}
	      else
		{
		  string->capacity /= 2;
		  return MYSTRING_STATUS_ERROR;

		}
	    }

	  string->data[string->size] = ch;
	  string->size++;
	  return MYSTRING_STATUS_SUCCESS;
	  
    }



  return MYSTRING_STATUS_ERROR;


}
char mystring_pop(MYSTRING hString)
{
  My_string *string =(My_string*)hString;
  char a = '\0';
  char b =  string->data[string->size - 1];


  
  if(string !=NULL)
    {
      if(string->size > 0)
	{
	  string->size--;
	  return b; 
	}
       
	 
    }
  return a;
}
char mystring_peek(MYSTRING hString)
{
  My_string *string = (My_string*)hString;
  char a = '\0';
  if(string->size > 0)
    {
      return string->data[string->size - 1];
    }

  return a;

}
char mystring_get(MYSTRING hString, int index)
{
  My_string *string = (My_string*)hString;

  if(string->size > index)
    {
      return string->data[index];
    }
  else 
    {
      return '\0';
    }
}
MyString_Status mystring_put(MYSTRING hString, int index, char ch)
{
  My_string *string = (My_string*)hString;

  if(string != NULL)
    {
      if(index <= string->size - 1 )
	{
	  string->data[index] = ch;
	  return MYSTRING_STATUS_SUCCESS;
	}
    }
  return MYSTRING_STATUS_ERROR;

}
MYSTRING mystring_init_substring(MYSTRING hStringSource, int index, int length)
{
  My_string *string = (My_string*)hStringSource;
  My_string *substring = NULL;
  int i = 0;
  substring = (My_string*)malloc(sizeof(My_string));
  if(substring != NULL)
    {
      substring->size = length;
      substring->capacity = length;
      substring->data = (char*)malloc(sizeof(char)*substring->capacity);
      if(substring == NULL)
	{
	  free(substring->data);
	  free(substring);
	  substring = NULL;
	  return NULL;
	}
      if(index - 1 <=  string->size && index - 1 + length <= string->size)
	{
	  for(; length + 1 >= 0; length--)
	   {
	     substring->data[i] = string->data[index + i];

	     i++;
	   }
	}
      else
	{
	  return NULL;
	}
    }
  return (MYSTRING)substring;

}
char* mystring_to_c_string(MYSTRING hString, char c_string_arr[], int arrSize)
{
  My_string *string = (My_string*)hString;
  int i;
  if(string != NULL)
    {
      if(arrSize >= 1)
	{

	  for(i=0; i < arrSize - 1; i++)
	    {
	      c_string_arr[i] = string->data[i];
	    }
	}
      return  &c_string_arr[0];
    }


  return NULL;

}
MyString_Status mystring_input(MYSTRING hString,
                               FILE * hFile,
                               int bIgnoreLeadingWhiteSpace,
                               int (* fTerminate)(char ch,
                                                  int * pbDiscardChar))
  My_string* string = (My_string*) hString;
char c;    
int discard = 0;
int realchar = 0;
if(hFile == NULL || string == NULL || fTerminate == NULL)
  {
    return MYSTRING_STATUS_ERROR;
  }
string->size = 0;
while(fscanf(hFile,"%c",&c) != EOF)
  {
    if(bIgnoreLeadingWhiteSpace)
      {
	if(!realchar && isalnum(c))
	  {
	    realchar = 1;
	  }
	if(realchar)
	  {
	    if(fTerminate(c,&discard))
	      {
		break;
	      }
	    if(discard == 0)
	      {
		mystring_push(hString,c);
	      }
	  }
      }
    else
      {
	if(fTerminate(c,&discard))
	  {
	    break;
	  }
	if(discard == 0)
	  {
	    mystring_push(hString,c);
	  }
      }
  }
if(feof(hFile))
  {
    return MYSTRING_STATUS_ERROR;
  }
return MYSTRING_STATUS_SUCCESS;
}
