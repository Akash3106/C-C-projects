# include <stdio.h>

void main(int argc, char *argv[])
{
 int p[20],a[20],b[20],br[20],tat[20],pr[20],gantt[100][2],n1,n2,n3,n4,c,d,i,e=0,f=0,g,time=0,t1,t2,t3,t4,t5,t6;
 float v1=0.0,v2=0.0;
 FILE *fp;
 char *filename;
 char ch;
 filename = argv[1];
 fp=fopen(filename,"r");
 while (fscanf(fp,"%d%d%d%d",&n1,&n2,&n3,&n4)!=EOF)
 {
  p[e]=n1;
  a[e]=n2;
  b[e]=n3;
  pr[e]=n4;
  br[e]=n3;
  e++;
 }
 while (1)
 {
   for (i=1;i<e;i++)
    if ((br[0]==0 || time<a[0]?1:pr[i]<pr[0]) && time>=a[i] && br[i]!=0)
    {
     t1=p[0];
     t2=a[0];
     t3=b[0];;
     t4=pr[0];;
     t5=br[0];
     t6=tat[0];


     p[0]=p[i];
     a[0]=a[i];
     b[0]=b[i];
     pr[0]=pr[i];
     br[0]=br[i];
     tat[0]=tat[i];


     p[i]=t1;
     a[i]=t2;
     b[i]=t3;
     pr[i]=t4;
     br[i]=t5;
     tat[i]=t6;
    }
   
  if (a[0]>time || br[0]==0)
  {
   if (f==0 || gantt[f-1][0]!=-1)
   {
    gantt[f][0]=-1;
    gantt[f++][1]=time;
   }
  }
  else
  if (br[0]!=0)
  {
   if (f==0 || gantt[f-1][0]!=p[0])
   {
    gantt[f][0]=p[0];
    gantt[f++][1]=time;
   }
   if (--br[0]==0)
    tat[0]=time+1-a[0];
  }
  time++;
  c=0;
  for (i=0;i<e;i++)
   if (br[i]!=0)
    c=1;
  if (c==0)
   break;
 }
 gantt[f][1]=time;
 printf ("%8s%8s%8s%8s%8s%8s\n\n","P","A","B","Pri","W","TAT");
 for (i=0;i<e;i++)
  printf ("\n%8d%8d%8d%8d%8d%8d\n",p[i],a[i],b[i],pr[i],tat[i]-b[i],tat[i]);
 for(i=0;i<e;i++)
  v1+=tat[i]-b[i];
 printf("\n\nAverage waiting time is:%f\n\n",v1/e); 

 for(i=0;i<e;i++)
  v2+=tat[i];
 printf("\n\nAverage turnaround time is:%f\n\n",v2/e);  


}

