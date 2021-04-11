//---------------------------------------------------------------------------------------------
//AUTHOR:              Peter
//FILENAME:            Lab2.cpp
//SPECIFICATION  :     To find the mean of n numbers using array.


#include<stdio.h>
/*
---------------------------------------------------------------------------------------
NAME:           mean
INPUT PARAM:    N, Number of data ; x, store the value; 
OUTPUT PARAM:   avg a float number , Give the avg(mean) of a given parameters
PURPOSE:        To find the mean of numbers enter by user.
*/
int mean(int N)
{
int i=1;
float x,avg,sum=0; //x store the value , avg is used to find the mean of numbers, sum is used
while(i<=N)
{ 
printf("Enter the value of %d = ",i);
scanf("%f",&x);
sum=sum+x;
++i;
}

avg=sum/N;
printf("Mean of %d is = %f\n",N, avg);
return 0;
}
void main()
{int N;  //N is a number of data to be insert

printf("Enter The length of array  = "); 
scanf("%d",&N);
mean(N);
}
