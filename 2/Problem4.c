
//---------------------------------------------------------------------------------------------
//AUTHOR:              Peter
//FILENAME:            Lab2.cpp
//SPECIFICATION  :     Program to concatenate two strings 


#include <stdio.h>
#include <string.h>
int main()
{ 
  char str1[1000], str2[1000];  // To Store two string we intialise two array str1,str2 
  char c[10] = " " ;   // C is Used to add space Between String str1 and str2
 
  printf("Enter the first string : ");
  gets(str1);
  printf("Enter the second string : ");
  gets(str2);
  strcat(str1,c);
  strcat(str1,str2);
  printf("The Concatenated text is : %s\n",str1);
  return 0;
}
