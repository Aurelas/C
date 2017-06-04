enum boolean {FALSE, TRUE}; 
typedef enum boolean Boolean; 

typedef struct _MY_SET *MY_SET; 
 
MY_SET my_set_init_default(); 
 
Boolean my_set_is_element(MY_SET hMY_SET, int item); //returns TRUE if item is in the set; exit on error 
 
Boolean my_set_is_empty(MY_SET hMY_SET); //returns TRUE if the set is empty; exit on error 
 
int my_set_size(MY_SET hMY_SET); //returns the number of elements in the set; -1 on error 
 
Boolean my_set_traverse(MY_SET hMY_SET, void (*visit)(int)); 
// call visit on each node in the set. (Use an inorder traversal of your AVL tree) 

Boolean my_set_add(MY_SET hMY_SET, int item); //adds item to the set if it is not already in it. 

Boolean my_set_remove(MY_SET hMY_SET, int item); 
//find and remove item from the set if it is present otherwise ignore. 

void my_set_destroy(MY_SET* p_hMY_SET); 
//destroy the data structure and set the handle pointed to by the argument to NULL. 
 
int my_set_height(MY_SET hMY_SET); //return the height of the AVL tree used for implementation. An empty tree has height 0, a tree with one node has height 1.

