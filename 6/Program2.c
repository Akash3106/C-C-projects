//---------------------------------------------------------------------------------------------
//AUTHOR:              Peter
//FILENAME:            Lab4.cpp
//SPECIFICATION  :     Generate binary number strings till the number inserted by user.
#include <stdio.h>
#include <string.h>
#define MAX 20
/*
---------------------------------------------------------------------------------------
NAME:           insert, delete 
INPUT PARAM:    queue,n,tem;temp:to store a data temporarily,Front;rear:They define the front and Rear value of queue.
OUTPUT PARAM:   temp : Have the generated Output by the binary_val fuction
PURPOSE:        Generate binary number strings.
*/

char queue[MAX][MAX], temp[MAX];
int front = -1, rear = -1;
void insert(char *ptr)  // This Function is to enqueue the number
{
	if(rear == MAX-1)
	{
	return;
	}
	if(front == -1 && rear == -1)
	front = rear = 0;
	else
	rear = rear + 1;
	strcpy(queue[rear],ptr); 
}
char* delete()            //  This Function is to dequeue the number
{
	if(front == -1)
	printf("\nEmpty Queue");
	else
	{
	strcpy(temp,queue[front]);
	if(front == rear)
	front = rear = -1;
	else
	front = front + 1;
	return temp;
	}	
}
void binary_val()  //fuction convert number into Binary forn 
{
	char tem[MAX];
	strcpy(temp,delete());  
	printf("%s\n",temp);
	strcpy(tem,temp);
	strcat(temp,"0");
	insert(temp);
	strcat(tem,"1");
	insert(tem);
}

int main()  //main Fuction takes the number from user
{
	int i,n;  // n : number user want to insert.
	printf("Enter the Number : "); 
	scanf("%d",&n);
	char temp[2] = "1";
	insert(temp);
	for(i = 1; i <= n; i++)
	binary_val();
	return 0;
}
