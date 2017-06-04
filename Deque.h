

#include <stdio.h>
#include <stdlib.h>

typedef char DequeData;
typedef struct node
{
  int numberOfShares;
  int CostPerShareAtPurchase;
  int CurrentCostPerShare; 
  DequeData NameOfStock;
  struct node *prev, *next;
  

}Node, *NodePtr;

typedef struct deque
{
  NodePtr head;
  NodePtr tail;
}DequeType, *DequePtr;


DequePtr initDeque();

void addFront(DequePtr d, int numberOfSharesData, int costPerShareData,char Stock_name);

void addBack(DequePtr d, int numberOfSharesData, int costPerShareData,char Stock_name);

void getFront(DequePtr d);

void getBack(DequePtr d);

void removeFront(DequePtr d);

void removeBack(DequePtr d);

int isEmpty(DequePtr d);

void empty(DequePtr d);

void destroyDeque(DequePtr d);
