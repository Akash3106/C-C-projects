//Question - 1
/*#include<stdio.h>
void main()
{int n, count=1 ;
float x,mean,sum=0; 
printf("Enter a the Value of n = ");
scanf("%d",&n);
while(count<=n)
{ 
printf("Enter the value of %d = ",count);
scanf("%f",&x);
sum=sum+x;
++count;
}

mean=sum/n;
printf("Mean of %d is = %f",n, mean);
}*/

//Question - 2
/*#include <stdio.h>
int main()
{
   int arr[100], position, i, n, value;
   printf("Enter the number of elements in array : ");
   scanf("%d", &n);
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
}*/
//Question-3
#include<stdio.h>
int main()
{
 int i,arr[5];
 for(i = 0;i<5;i++)
 scanf("%d",&arr[i]);
 
for(i = 0; i<5; i++)
 sum=arr[i+1] + arr[i]
 
 //Question-4
/*#include <stdio.h>
#include <string.h>
int main()
{
  char a[1000], b[1000];

  printf("Enter the first string : ");
  scanf("%s",a);
  printf("Enter the second string : ");
  scanf("%s",b);

  printf("The Concatenated text is : %s %s",a,b);
  return 0;
}
*/
