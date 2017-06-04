#include "Deque.h"

DequePtr initDeque()
{
  DequePtr d;

  if((d = (DequePtr)malloc(sizeof(DequeData))) == NULL)
    {
      fprintf(stderr, "Out of memory\n");
      exit(1);
    }

  d->head = NULL;
  d->tail = NULL;
  return d;

}
void addFront(DequePtr d, int numberOfSharesData, int costPerShareData, char Stock_name)
{
  NodePtr newNode;
 
  newNode = (NodePtr)malloc(sizeof(Node));
  
  if (newNode == NULL)
    {
      fprintf(stderr, "Malloc Error\n");
      exit(1);
    }
  newNode->numberOfShares = numberOfSharesData;
  newNode->CostPerShareAtPurchase = costPerShareData;
  newNode->CurrentCostPerShare = rand()%100;
  newNode->next = NULL;
  newNode->prev = NULL;
  newNode->NameOfStock = Stock_name;
  if(d->head == NULL)
    {
      
      d->head = newNode;
      d->tail = newNode;
     
    }
  else
    {
      
      newNode->next = d->head;
      d->head->prev = newNode;
      d->head = newNode;
    

    }

}
void addBack(DequePtr d, int numberOfSharesData, int costPerShareData, char Stock_name)
{
  NodePtr newNode;

  newNode = (NodePtr)malloc(sizeof(Node));
  if(newNode == NULL)
    {
      fprintf(stderr,"Out of memory\n");
      exit(1);
    }
  newNode->numberOfShares = numberOfSharesData;
  newNode->CostPerShareAtPurchase = costPerShareData;
  newNode->CurrentCostPerShare = rand()%100;
  newNode->next = NULL;
  newNode->prev = NULL;
  newNode->NameOfStock = Stock_name;
  if(d->head == NULL)
    {
      d->head = newNode;
      d->tail = newNode;
     
    }
  else
    {
      d->tail->next = newNode;
      newNode->prev = d->tail;
      newNode->next = NULL;
      d->tail = newNode;
     
    }

}
void getFront(DequePtr d)
{
  if(d->head->NameOfStock == 'I'|| d->head->NameOfStock == 'i')
    {
      printf("The name of the stock you currently own is Intel!\n");
    }
  if(d->head->NameOfStock == 'A' || d->head->NameOfStock == 'a')
    {
      printf("The name of the stock you currently own is Amazon!\n");
    }
if(d->head->NameOfStock == 'G' || d->head->NameOfStock == 'g')
  {
    printf("The name of the stock you currently own is Google!\n");
  }
 if(d->head->NameOfStock == 'E' || d->head->NameOfStock == 'e')
   {
     printf("The name of the stock you currently own is Ebay!\n");
   }
  printf("The current number of shares you own of the stock is : %d\n" , d->head->numberOfShares);
  printf("The cost of the share per unit at the time you bought the stock was : %d\n" , d->head->CostPerShareAtPurchase);
  d->head->CurrentCostPerShare = rand()%100;
  printf("The current cost per share that you own is : %d\n",  d->head->CurrentCostPerShare);
  return;
}
void getBack(DequePtr d)
{
  if(d->tail->NameOfStock == 'I'|| d->tail->NameOfStock == 'i')
    {
      printf("The name of the stock you current own is Intel!\n");
    }
  if(d->tail->NameOfStock == 'A' || d->tail->NameOfStock == 'a')
    {
      printf("The name of the stock you currently own is Amazon!\n");
    }
  if(d->tail->NameOfStock == 'G' || d->tail->NameOfStock == 'g')
    {
      printf("The name of the stock you currently own is Google!\n");
    }
  if(d->tail->NameOfStock == 'E' || d->tail->NameOfStock == 'e')
    {
      printf("The name of the sotck you currently own is Ebay!\n");
    }
  printf("The current number of shares you own of the stock is : %d\n" , d->tail->numberOfShares);
  printf("The cost of the share per unit at the time you bought the stock was : %d\n" , d->tail->CostPerShareAtPurchase);
  printf("The current cost per share that you own is : %d\n",  d->tail->CurrentCostPerShare);
  return;
}
void destroyDeque(DequePtr d)
{
  NodePtr temp;
  if(d->head == NULL)
    {
      return;
    }
  while(d->head != NULL)
    {
      temp = d->head;
      d->head = d->head->next;
      free(temp);

    }




}
void removeFront(DequePtr d)
{
  NodePtr temp = d->head;
  if(temp == NULL)
    {
      printf("Queue is empty!\n");
      exit(1);
    }
  else
    {
     
      d->head = temp->next;
      free(temp);
      if(temp == NULL)
	{
	  d->tail = NULL;

	}
    }


}
void removeBack(DequePtr d)
{
  NodePtr temp;
  temp = d->tail;
  if(temp == NULL)
    {
      printf("Queue is empty!\n");
      exit(1);
    }
  else
    {
     
      d->tail = d->tail->prev;
     
      free(temp);
      d->tail->next = NULL;
      if(temp == NULL)
	{
	  d->head = NULL;
	}
    }

}
int isEmpty(DequePtr d)
{
  if(d->head == NULL)
    {
      fprintf(stderr,"The list is empty!\n");
      return 0;
    }
  else
    {
      fprintf(stderr,"The list contains data!\n");
      return 1;
    }
  
}
void empty(DequePtr d)
{
  d->head = NULL;
  d->tail = NULL;

}
