//---------------------------------------------------------------------------------------------
//AUTHOR:              Peter
//FILENAME:            Lab2.cpp
//SPECIFICATION  :     Insert a number at a given location in an array.


#include <stdio.h>
/*
---------------------------------------------------------------------------------------
NAME:           insertion
INPUT PARAM:    n, Number of data ; 
OUTPUT PARAM:   Gives output array arr after inserting a data in desired place.
PURPOSE:        To insert values in between array.
*/
int insertion(int n)
{  
   int arr[100], position, i, value; //intailise arr to store data in it , postion varible takes a postion at which data will store , value = data you want to store 
   for (i = 0; i < n; i++)
      {printf("arr[%d] = ", i);
      scanf("%d", &arr[i]);}
   printf("Enter the number to be inserted : ");
   scanf("%d", &value);
   printf("Enter the postion at which the number has to be added : ");
   scanf("%d", &position);
   for (i = n - 1; i >= position - 1; i--)
      arr[i+1] = arr[i];
   arr[position] = value;
   printf("The array after insertion of %d is : \n", value);
   for (i = 0; i <= n; i++)
      printf("arr[%d] = %d\n",i,arr[i]);
   return 0;
}
int main()
{
   int  n; //Lenght of array arr
   printf("Enter the number of elements in array : ");
   scanf("%d", &n);
   insertion(n);
   return 0;
}
