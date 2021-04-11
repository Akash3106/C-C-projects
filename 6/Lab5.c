//---------------------------------------------------------------------------------------------
//AUTHOR:              Peter
//FILENAME:            Lab4.cpp
//SPECIFICATION  :  	Use a stack implementation, to check an arithmetic expression.

#include<stdio.h>
#include<string.h>

/*
---------------------------------------------------------------------------------------
NAME:           isBalance,push,pop
INPUT PARAM:    a[]:Takes the input string
OUTPUT PARAM:   return Balance and Unbalance as Output
PURPOSE:        To check an arithmetic expression
*/

char st[20];
int top=-1;
void psh(char);
char pop();
int isBalance()
{
char a[20],t;
int i,f=1;
scanf("%s",a);
for(i=0;i<strlen(a);i++)
{
if(a[i]=='('||a[i]=='{'||a[i]=='[')
psh(a[i]);
if(a[i]==')'||a[i]=='}'||a[i]==']')
{
if(top==-1)
f=0;
else
{t=pop();
if(a[i]==')'&&(t=='['||t=='{'))
f=0;
if(a[i]=='}'&&(t=='('||t=='['))
f=0;
if(a[i]==']'&&(t=='{'||t=='('))
f=0;
}
}
}
if(top>=0)
f=0;
if(f==0)
printf("Unbalanced\n");
else
printf("Balanced\n");
return 0;
}
int main()
{
printf("Enter the string : ");
isBalance();
}
void psh(char a)
{
st[++top]=a;
}
char pop()
{
return st[top--];
}
