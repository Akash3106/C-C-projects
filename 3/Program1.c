//---------------------------------------------------------------------------------------------
//AUTHOR:              Peter
//FILENAME:            Lab3.cpp
//SPECIFICATION  :     Create Employee database.



#include<stdio.h>
#include <stdlib.h>
#include <string.h>

/*
---------------------------------------------------------------------------------------
NAME:           insert,disp,update
INPUT PARAM:    id,name,slry,expr,dprt 
OUTPUT PARAM:   id and expr,int display id and experience of empolyee ;name and dprt ,string display nameand department of empolyee ;slry , float display salary of empolyee, 
PURPOSE:        To create data of employees and modify it.
*/
struct employ
{
 int id;
 char name[100];
 float slry;
 int expr;
 char dprt[80];
}empy;
//    FUNCTION TO INSERT RECORDS TO THE FILE
void insert()
{
 FILE *fp;
 fp = fopen("Record", "a");
 printf("********DETAILS OF Employee*******\n");
 printf("Employee ID = ");
 scanf("%d", &empy.id);
 printf("Employee Name = ");
 scanf("%s", empy.name);
 printf("Salary = ");
 scanf("%f", &empy.slry);
 printf("Experience = ");
 scanf("%d", &empy.expr);
 printf("Department = ");
 scanf("%s", empy.dprt);
 fwrite(&empy, sizeof(empy), 1, fp);
 fclose(fp);
}
//    FUNCTION TO DISPLAY RECORDS
void disp()
{
 FILE *fp1;
 fp1 = fopen("Record", "r");
 while (fread(&empy, sizeof(empy), 1, fp1))
 {
 printf("\n\n********DETAILS OF Employee*******\n");
 printf("\nEmployee ID = %d",empy.id);
 printf("\nEmployee Name = %s",empy.name);
 printf("\nSalary = %.2f",empy.slry);
 printf("\nExperience = %d",empy.expr);
 printf("\nDepartment = %s\n\n",empy.dprt);
 }
 fclose(fp1);
}
//    FUNCTION TO UPDATE THE RECORD
void update()
{
 FILE *fpt;
 FILE *fpo;
 int s, r, ch;
 printf("Enter Employee-ID to update:");
 scanf("%d", &r);
 if (r == 0)
 {
  printf("Employee ID %d is not Available in the file", r);
 }
 else
 {
  fpo = fopen("Record", "r");
  fpt = fopen("TempFile", "w");
  while (fread(&empy, sizeof(empy), 1, fpo))
  {
   s = empy.id;
   if (s != r)
    fwrite(&empy, sizeof(empy), 1, fpt);
   else
   {
    printf("Employee Name = ");
    scanf("%s", empy.name);
    printf("Salary = ");
    scanf("%f", &empy.slry);
    printf("Experience = ");
    scanf("%d", &empy.expr);
    printf("Department = ");
    scanf("%s", empy.dprt);
    fwrite(&empy, sizeof(empy), 1, fpt);
   }
  }
  fclose(fpo);
  fclose(fpt);
  fpo = fopen("Record", "w");
  fpt = fopen("TempFile", "r");
  while (fread(&empy, sizeof(empy), 1, fpt))
  {
   fwrite(&empy, sizeof(empy), 1, fpo);
  }
  fclose(fpo);
  fclose(fpt);
  printf("RECORD UPDATED");
 }
}


//FUNCTION TO CHECK THE FILE IS EMPTY OR NOT
int empty()
{
 int c = 0;
 FILE *fp;
 fp = fopen("Record", "r");
 while (fread(&empy, sizeof(empy), 1, fp))
  c = 1;
 fclose(fp);
 return c;
}
// MAIN PROGRAM
void main()
{
 int c, emp;  //c is the choice of user
 do
 {
  printf("\n---------Select your choice---------\n");
  printf("\n1. ADD EMPLOYEE\n2. DISPLAY EMPOLYEES");
  printf("\n3. UPDATE EMPLOYEE DETAILS");
  printf("\n4. EXIT");
  printf("\n\n------------------------------------------\n");
  printf("\nEnter your choice:");
  scanf("%d", &c);
  printf("\n");
  switch (c)
  {
  case 1:
   insert();
   break;
  case 2:
   emp = empty();
   if (emp == 0)
    printf("\nThe file is EMPTY\n");
   else
    disp();
   break;
  case 3:
   update();
   break;
  case 4:
   exit(1);
   break;
  default:
   printf("\nYour choice is wrong\nPlease try again...\n");
   break;

  }
 } while (c != 7);
}
