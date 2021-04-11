/*#include<stdio.h>

int main()
{
int a;
printf("Enter a number : ");
scanf("%d",&a);
if(a%2==0)
printf("Number is Even ");
else
printf("Number is odd ");
return(0);
}
*/


/*
#include<stdio.h>

void main()
{
int i;
float f;
scanf("%d",&i);
f = i;
printf("%f",f);
}
*/


/*#include <stdio.h>

 int add(int *n1, int *n2) 
{
   int sum;
   sum = *n1 + *n2;
   return sum;
}

int main()
{
   int a, b, sum;
   
   printf("\n Add two numbers using Pointer:\n"); 
 
   printf(" Input the first number : ");
   scanf("%d", &a);
   printf(" Input the second  number : ");
   scanf("%d", &b);   
   sum = add(&a, &b);
   printf(" The sum is %d\n\n", sum);
   return 0;
}
*/

#include<stdio.h>

 void printDigit(int number) 
{ 
int nt,cnum;
int reversedNum = 0;
int b,result =0;
nt=number;
cnum=number;
    while (number != 0) {
        reversedNum = reversedNum * 10 + number % 10;
        number = number / 10;
    }
	

    while (nt > 0) {
        b=nt % 10;
	printf("%d",b);
        result = result + (b);
        nt = nt/ 10;

        if (nt > 0) {
            printf(" + ");
        }
    }
   printf(": = %d" ,result);

   if(result%9 == 0)
   printf("\n%d is divisible by 9",nt);
   else
   printf("\n%d is not divisible by 9",cnum);

}

int main()
{
int number;
printf("Please enter a positive integer (negative to end): "); 
scanf("%d",&number);
if (number > 0)
{printf("The digits and sum are: ");
	printDigit(number);}
else
printf(" Please enter a positive integer ");
return 0; 
}
