#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct node
{
int data;
struct node *left, *right;
}node;

// Function to create a new BST node.

node *createNode(int item)
{
node *newNode = (struct node *)malloc(sizeof(node));
newNode->data = item;
newNode->left = NULL;
   newNode->right = NULL;
return newNode;
}

//Function to insert a new node with given key in BST
struct node* insert(node* root, int key)
{
// If the tree is empty, return a new node
if (root == NULL) return createNode(key);
  
// Otherwise, recur down the tree
if (key < root->data)
root->left = insert(root->left, key);
else if (key > root->data)
root->right = insert(root->right, key);
  
return root;
}

node * findMinValue(node* root)
{
node* current = root;
  
while (current && current->left != NULL)
current = current->left;
  
return current;
}
  
//Function deletes the key and returns the new root
node* deleteNode(node* root, int key)
{
// tree is empty
if (root == NULL) return root;
  
// If the key to be deleted is smaller than the root's key, then recur to left subtree
if (key < root->data)
root->left = deleteNode(root->left, key);
  
// If the key to be deleted is greater than the root's key, then recut to right subtree
else if (key > root->data)
root->right = deleteNode(root->right, key);
  
// if match found
else
{
// node with only one child or no child
if (root->left == NULL)
{
node *temp = root->right;
free(root);
return temp;
}
else if (root->right == NULL)
{
node *temp = root->left;
free(root);
return temp;
}
  
node* temp = findMinValue(root->right);
root->data = temp->data;
root->right = deleteNode(root->right, temp->data);
}
return root;
}

int heightOfTree(node* root)
{
if (root == NULL) return 0;
  
int lh = heightOfTree(root->left);
int rh = heightOfTree(root->right);
  
if (lh> rh) return(lh + 1);
return(rh+ 1);

}

void levelOrderTraversal(node* root, int level)
{
if (root == NULL) return;
if (level == 1) printf("%d ",root->data );
else if (level > 1)
{    
levelOrderTraversal(root->left, level-1);
      
levelOrderTraversal(root->right, level-1);
}
}

void printTree(node* root)
{
int h = heightOfTree(root);
int i;
for (i = 1; i <= h; i++) {
   levelOrderTraversal(root, i);
   printf("\n");
   }

}

void printPaths(node* root) {
  int path[1000];
  printPathsRecur(root, path, 0);
}

void printPathsRecur(struct node* root, int path[], int pathLen) {
  if (root==NULL) return;

  path[pathLen] = root->data;
  pathLen++;

  if (root->left==NULL && root->right==NULL) {
    printArray(path, pathLen);
  }
  else {
    printPathsRecur(root->left, path, pathLen);
    printPathsRecur(root->right, path, pathLen);
  }
}

void menu(){
   printf("1.Create Binary search tree\n2.Delete a Node\n3.print Tree\n4.Quit\n");
}
  
int main()
{
srand(time(NULL));
int data,n,choice,i;
node*root = NULL;
do{
   menu();
   printf("Enter choice: ");
   scanf("%d",&choice);
  
   switch(choice){
       case 1:{
           printf("Enter number of nodes in tree : ");
           scanf("%d",&n);
           for(i=0;i<n;i++){
               root = insert(root , rand()%100);
               }
               break;
           }
           case 2:{
               printf("Enter data to be deleted: ");
               scanf("%d",&data);
               root = deleteNode(root,data);
               break;
           }
           case 3:{
               printTree(root);
               printf("\n\n");
               break;
           }
           case 4:{
               printf("Good Bye!\n");
               break;
           }
           default:{
               printf("Invalid choice\n");
               break;
           }
       }
  
   }while(choice!=4);
return 0;
}
