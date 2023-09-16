#include<stdio.h> 
int main()
{
    int bt[20],p[20],wt[20],tat[20],priority[20],i,j,n,total=0,pos,temp;
	float average_wt,average_tat;
    printf("Enter Total Number of Process:");
    scanf("%d",&n);
    printf("\nEnter Burst Time and Priority\n");
    for(i=0;i<n;i++)
    {
        printf("\nP[%d]\n",i+1);
        printf("Burst Time:");
        scanf("%d",&bt[i]);
        printf("Priority:");
        scanf("%d",&priority[i]);
        p[i]=i+1;          
    }
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(priority[j]<priority[pos])
            {
	            pos=j;
            }
		}
        temp=priority[i];
        priority[i]=priority[pos];
        priority[pos]=temp;
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    wt[0]=0;    
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            {
			wt[i]+=bt[j];
            }
        total+=wt[i];
    }
    average_wt=total/n;      
    total=0;
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i]; 
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
    average_tat=total/n;     
	printf("\n\nAverage Waiting Time=%f",average_wt);
    printf("\nAverage Turnaround Time=%f\n",average_tat);
    return 0;
}
