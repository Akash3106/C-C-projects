//---------------------------------------------------------------------------------------------
//AUTHOR:              Peter
//FILENAME:            Lab3.5.cpp
//SPECIFICATION  :     Priority Scheduling




#include<stdio.h>


/*
---------------------------------------------------------------------------------------
NAME:           main,avg_waiting,avg_turn
INPUT PARAM:    p:processor,wt:waiting_time,bt:burst_time,tat:turn around time,pr:priority of processor. 
OUTPUT PARAM:   p[i],bt[i],wt[i],tat[i]:accoding to priority this arrange the processor and calculate thier Turn aound time and waiting time
PURPOSE:        task is given in the file , pass the file as argument to Schedule the processor using priority.
*/
int avg_waiting(int n, int wttotal)
{
int avg_wt;
avg_wt=wttotal/n;
printf("\n\nAverage Waiting Time=%d",avg_wt);
return 0;
}


int avt_turn(int n, int total)
{
int avg_tat;

avg_tat=total/n;
printf("\nAverage Turnaround Time=%d\n",avg_tat);
}

int main(int argc, char *argv[])

{

    int p[20],bt[20],wt[20],tat[20],n1,n2,n3,pr[20],i,j,n=0,wttotal=0,total=0,pos,temp,avg_wt,avg_tat;
    int count=0;
    FILE *fp;
    char *filename;
    
    filename = argv[1];     //argument value is saved in filename
    fp=fopen(filename,"r");  //read the file
    while (fscanf(fp,"%d%d%d",&n1,&n2,&n3)!=EOF)
    {
     p[n]=n1;
     pr[n]=n2;
     bt[n]=n3;
     n++;
 }
    //sorting priority and process number in ascending order using selection sort
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
                pos=j;
        }
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;

    }

    wt[0]=0; //waiting time for first process is zero

    //calculate waiting time

    for(i=1;i<n;i++)

    {

        wt[i]=0;

        for(j=0;j<i;j++)

            wt[i]+=bt[j];

        wttotal+=wt[i];

    }

    total=0;
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");


    for(i=0;i<n;i++)

    {

        tat[i]=bt[i]+wt[i];    

        total+=tat[i];

        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);  //calculate turn around time

    }

    avg_waiting(n,wttotal);
    avt_turn(n,total);
    
    
return 0;

}
