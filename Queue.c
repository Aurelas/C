#include "Deque.h"
#include <time.h>
void Display_Stocks(void);
int main(int argc, char* argv[])
{
  int User_capital = 1000;
  int User_choice;
  int User_buy_choice;
  int User_sell_choice;
  int User_check_choice;
  char Stock_name;
  int Number_of_shares =  0;
  int Cost_per_share = 0;
  char User_answer = 'y';
  DequePtr d = initDeque();
  srand(time(NULL));
  
  while(User_answer == 'y')
    {
      Display_Stocks();

    
      printf("Choose an option!\n");
      printf("\n");
      printf("1:Buy Stock\n");
      printf("2:Sell Stock\n");
      printf("3:Check Stock\n");
      printf("4:Exit\n");
      scanf("%d",&User_choice);
      
      if(User_choice == 1)
	{
	  printf("Do you with to add a Stock to the front or the back of the list?\n");
	  printf("1:Front\n");
	  printf("2:Back\n");
	  scanf("%d" , &User_buy_choice);
	  if(User_buy_choice == 1)
	    {
	      printf("Please enter the following information about the stock!\n");
	      printf("-----------------------------------------------------------\n");
	      printf("Print the first initial of the stock you wish to buy!\n");
	      scanf(" %c" , &Stock_name);
	      printf("How many shares did you wish to buy?\n");
	      scanf("%d" , &Number_of_shares);
	      printf("How much did each share cost?\n");
	      scanf("%d" , &Cost_per_share);
	      addFront(d,Number_of_shares,Cost_per_share,Stock_name);
	      User_capital = User_capital - (Number_of_shares * Cost_per_share);
	    }
	  else
	    {
	      printf("Please enter the following information about the stock!\n");
	      printf("------------------------------------------------------------\n");
	      printf("Print the first initial of the stock you wish to buy!\n");
	      scanf(" %c" , &Stock_name);
	      printf("How many shares did you wish to buy?\n");
	      scanf("%d" , &Number_of_shares);
	      printf("How much did each share cost?\n");
	      scanf("%d" , &Cost_per_share);
	      addBack(d,Number_of_shares,Cost_per_share,Stock_name);
	      User_capital = User_capital - (Number_of_shares * Cost_per_share);
	    }
	}
      if(User_choice == 2)
	{
	  printf("Do you wish to sell a Stock at the fron or back of the list?\n");
	  printf("1:Front\n");
	  printf("2;Back\n");
	  scanf("%d" , &User_sell_choice);
	  if(User_sell_choice == 1)
	    {
	    
	      User_capital = User_capital + (d->head->numberOfShares * (d->head->CurrentCostPerShare - d->head->CostPerShareAtPurchase));
	      removeFront(d);
	    }
	  else
	    {
	     
	      User_capital = User_capital + (d->tail->numberOfShares * (d->tail->CurrentCostPerShare - d->tail->CostPerShareAtPurchase));
	      removeBack(d);
	    }

	}
      if(User_choice == 3)
	{
	  printf("Do you wish to check the Stock at the front or the back?\n");
	  printf("1:Front\n");
	  printf("2:Back\n");
	  scanf("%d" , &User_check_choice);
	  if(User_check_choice == 1)
	    {
	      getFront(d);
	    }
	  else
	    {
	      getBack(d);
	    }

	  if(d->head->CurrentCostPerShare > 50 || d->head->CurrentCostPerShare > d->head->CostPerShareAtPurchase)
	    {
	      printf("You should probably sell the Stock located at the front of the list!\n");
	    }
	  else
	    {
	      printf("Hold onto your Stock for a better price!\n");
	    }
	}
      if(User_choice == 4)
	{
	  break;
	}
      
      printf("\n");
      printf("User Capital : %d\n", User_capital);

    }

    
 



  destroyDeque(d);
  return 0;
}
void Display_Stocks(void)
{

  printf("Stock 1: Amazon, Starting cost per Share: %d\n", rand()%100);
  printf("Stock 2: Intel, Staring cost per Share %d\n",rand()%100);
  printf("Stock 3: Ebay, Starting cost per Share %d\n" , rand()%100);
  printf("Sotck 4: Google, Starting cost per Share %d\n" , rand()%100);


}
