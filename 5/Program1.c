//---------------------------------------------------------------------------------------------
//AUTHOR:              Peter
//FILENAME:            Lab5.cpp
//SPECIFICATION  :     The Binary tree creation

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/*
---------------------------------------------------------------------------------------
NAME:           levelOrderTraversal; printTree; heightOfTree; insert; createNode;
INPUT PARAM:    data:contains the value of nodes; root;
OUTPUT PARAM:   printTree:This function Print the whole tree in BFS.
PURPOSE:        Creation of Binary tree in level order traversal line by line .
*/

typedef struct node
{
int data;
struct node *left, *right;
}node;

// Function to create a new BST node
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
node *search(node* root, int data)
{
if(root == NULL)
printf("\nThe item is not found\n-----------------------------");
else if(data < root->data)
{
root->left=search(root->left, data);
}
else if(data > root->data)
{
root->right=search(root->right, data);
}
else
printf("\nElement found is: %d\n----------------------------", root->data);
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

void main()
{
int data, ch, i, n,choice;
node *root=NULL;
srand(time(NULL));

while (1)
{
printf("\n----------BINARY TREE----------");
printf("\n1.Create an integer binary tree");
printf("\n2.Search Element in Binary Search Tree");
printf("\n3.Remove a specific node in the tree");
printf("\n4.Display the tree in in the console\n5.Exit");
printf("\nEnter your choice: ");
scanf("%d", &ch);
switch (ch)
{
case 1:printf("----------------------------------------\nEnter 1. To insert a data\nEnter 2. Use a Random data\nEnter your Choice: ");
scanf("%d",&choice);
 if(choice==1){
printf("\nEnter the Number of nodes " );
scanf("%d", &n);
printf("\nEnter the values separated by a space \n");
for(i=0; i<n; i++)
{
scanf("%d", &data);
root=insert(root, data);
}
}
if(choice==2){
printf("Enter number of nodes in tree : ");
           scanf("%d",&n);
           for(i=0;i<n;i++){
               root = insert(root , rand()%100);
        }
}
break;
case 2: printf("\nEnter the element to search: ");
scanf("%d", &data);
root=search(root, data);
break;
case 3: printf("\nEnter the element to delete: ");
scanf("%d", &data);
root=deleteNode(root, data);
break;
case 4:{
	printTree(root);
        printf("----------------------------------------\n");
        break;
        }
break;
case 5: exit(0);
default:printf("\nWrong option");
break;
}
}
}
