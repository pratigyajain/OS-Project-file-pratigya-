#include<stdio.h>
int main() 
{
	int totalp, i, total_wt=0, total_tat=0;
	float average_wt, average_tat;
	int BT[4];
	int WT[4];
	int TAT[i];
	i=0;
	WT[i]=0;
	totalp=4;
	printf("Enter The Number of Processes: \n");
	scanf("%d", &totalp);
	printf("Enter The Burst Time of Processes: \n");
	for(i=0; i<totalp; i++)
	{
		scanf("%d", &BT[i]);
	}
	i=0;
	printf("Waiting Time for all Processes are \n");
	printf("p[%d]=%d \n", i, WT[i]); 
	for(i=0; i<totalp; i++)
	{
		WT[i]=WT[i-1]+BT[i-1];
		printf("p[%d]=%d \n", i, WT[i]);
	}
	for(i=0; i<totalp; i++)
	{
		total_wt=total_wt+WT[i];
	}
	average_wt=(float)total_wt/totalp;
	printf("Total Waiting Time=%d \n", total_wt);
	printf("average Waiting Time=%f \n", average_wt);
	printf("turmaround Time for all Processes are \n");
	for(i=0; i<totalp; i++)
	{
		TAT[i]=BT[i]+WT[i];
		printf("p[%d]=%d \n", i, TAT[i]);
	}
	for(i=0; i<totalp; i++)
	{
		total_tat=total_tat+TAT[i];
	}
	average_tat=total_tat/totalp;
	printf("Total Turnaround Time=%d \n", total_tat);
	printf("average turnaround time=%f \n", average_tat);
	return 0;
}
