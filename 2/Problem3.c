//---------------------------------------------------------------------------------------------
//AUTHOR:              Peter
//FILENAME:            Lab2.cpp
//SPECIFICATION  :     Find a pair of elements with sum K in an unsorted array.


#include <stdio.h>
#define MAX 100000
 
 /*
---------------------------------------------------------------------------------------
NAME:           pairs
INPUT PARAM:    A,array to store a data ; A_size, size ; sum, add value s in loop .
OUTPUT PARAM:   count, An integer which count a number of pairs.
PURPOSE:        To count no. of Pairs , which satisfy the value of K(sum).
*/
void pairs(int A[], int A_size, int sum) //Fuction 
{
    int i, temp,count=0; //count is use to count the no of pairs.
 
    /*initialize hash set as 0*/
   int s[MAX] = { 0 };
 
    for (i = 0; i < A_size; i++) 
    {
        temp = sum - A[i];
        if (s[temp] == 1)
            count=count+1;
        s[A[i]] = 1;
    }
    printf("Number of Pairs of elements with sum K is  %d \n",count);
}
 
/* Driver Code */
int main()
{
    int A[5]; //Intialising the array.
    int K,i; // K is the sum of pairs.
    int A_size = sizeof(A) / sizeof(A[0]);  //sizeof(A) is the total size occupied by the array. sizeof(A[0]) is the size of the first element in the array.
    printf("Enter value of array A \n");
    for(i = 0 ; i<5;i++)
    {
     printf("Enfer value of A[%d] : ",i+1);
     scanf("%d",&A[i]);
     }
    printf("Enter the value of K : ");
    scanf("%d",&K);
    pairs(A, A_size, K);
    return 0;
}
