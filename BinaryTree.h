#define MAX_SIZE    100

typedef char    NodeData[MAX_SIZE];
typedef struct BinaryNode
{
  NodeData data;
  struct BinaryNode * left;
  struct BinaryNode * right;
} BinaryNode, *BinaryTreePtr;

typedef struct BinaryTree
{
  BinaryNode * root;
} BinaryTree;

int Has_Left(BinaryNode *node);
int Has_Right(BinaryNode *node);
int Is_Leaf(BinaryNode *node);
BinaryTree *initBinaryTree();
int Is_Empty(BinaryTree * tree);
BinaryNode* Add_Root(BinaryTree* tree, NodeData data);
BinaryNode* Add_Child(BinaryNode* node, NodeData the_data);
void Empty_Subtree(BinaryNode* node);
void Destroy_Tree(BinaryTree* tree);
int Num_Node_Subtree(BinaryNode* node);
int Num_Leaves_Subtree(BinaryNode* node);
int Height_Subtree(BinaryNode* node);

