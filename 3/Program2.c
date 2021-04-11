//---------------------------------------------------------------------------------------------
//AUTHOR:              Peter
//FILENAME:            Lab3.cpp
//SPECIFICATION  :     Creating and modifing Doubly linked list.



#include <stdio.h>
#include <stdlib.h>

/*
---------------------------------------------------------------------------------------
NAME:           createList,displayList,reverseList,deleteFirst.
INPUT PARAM:    choice-Ask for the choice of user, data - data to be inserted in doubly linked list.
OUTPUT PARAM:   data - Data of list is displayed when user choose display function. 
PURPOSE:        Creating and modifing Doubly linked list and some more fuctions.
*/


/*
 * Basic structure of Node
 */
struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head, *last;





void createList(int n);  /*This program is used to create Doubly Linked list of 5 data.*/
void displayList();      /*This program is used to display Doubly Linked list of 5 data.*/
void reverseList();      /*This program is used to reverse Doubly Linked list of 5 data.*/
void deleteFirst();      /*This program is used to delete First node of Doubly Linked list of 5 data.*/


int main()
{
    int n, data, choice=1;

    head = NULL;  //intialising head 
    last = NULL; //intialising last

    /*
     * Runs forever until user chooses 0
     */
    while(choice != 0)
    {
        printf("1. Create List the doubly linked list\n");
        printf("2. Display the linked list \n");
        printf("3. Rverse the doubly linked list\n");
        printf("4. Delete the first node in your doubly Linked list\n");
        printf("0. Exit\n");
        printf("Enter your choice : ");

        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                n=5;
                createList(n);
                break;
            case 2:
                displayList();
                break;
            case 3:
                reverseList();
                break;
            case 4:
                deleteFirst();
                break;
            case 0:
                break;
            default:
                printf("Error! Invalid choice. Please choose between 0-3");
        }

        printf("\n\n\n");
    }

    return 0;
}


// Creates a doubly linked list of n nodes.

void createList(int n)
{
    int i, data;
    struct node *newNode;

    if(n >= 1)
    {
        /*
         * Create and link head node
         */
        head = (struct node *)malloc(sizeof(struct node));

        printf("Enter data of 1 node: ");
        scanf("%d", &data);

        head->data = data;
        head->prev = NULL;
        head->next = NULL;

        last = head;

        /*
         * Create and link rest of the n-1 nodes
         */
        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            printf("Enter data of %d node: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->prev = last; // Link new node with the previous node
            newNode->next = NULL;

            last->next = newNode; // Link previous node with the new node
            last = newNode; // Make new node as last/previous node
        }

        printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}



 // Display the content of the list from beginning to end
 
void displayList()
{
    struct node * temp;
    int n = 1;

    if(head == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        temp = head;
        printf("DATA IN THE LIST:\n");

        while(temp != NULL)
        {
            printf("DATA of %d node = %d\n", n, temp->data);

            n++;

            /* Move pointer to next node */
            temp = temp->next;
        }
    }
}



 // Reverse order of the doubly linked list

void reverseList()
{
    struct node *current, *temp;

    current = head;
    while(current != NULL)
    {
        
         //Swap the previous and next address fields of current node
        
        temp = current->next;
        current->next = current->prev;
        current->prev = temp;

        /* Move the current pointer to next node which is stored in temp */
        current = temp;
    }
    
    //Swap the head and last pointers
    temp = head;
    head = last;
    last = temp;
    printf("List is Reversed");
}

void deleteFirst()
{
    struct node * toDelete;

    if(head == NULL)
    {
        printf("Unable to delete. List is empty.\n");
    }
    else
    {
        toDelete = head;

        head = head->next; // Move head pointer to 2 node
        
        if (head != NULL)
            head->prev = NULL; // Remove the link to previous node

        free(toDelete); // Delete the first node from memory
    }
    printf("First node was Deleted");
}
