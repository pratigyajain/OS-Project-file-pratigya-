#include<stdio.h> 
int main() 
{ 
    int i, limit, total = 0, x, counter = 0, time_quantum; 
    int wt = 0, tat = 0, arr_time[10], bt[10], temp[10]; 
    float avr_wt, avr_tat;
    printf("\nEnter Number of Process:\t"); 
    scanf("%d", &limit); 
    x = limit; 
    for(i = 0; i < limit; i++) 
    {
        printf("\nEnter Details of Process[%d]\n", i + 1);
        printf("Arrival Time:\t");
        scanf("%d", &arr_time[i]);
        printf("Burst Time:\t");
        scanf("%d", &bt[i]); 
        temp[i] = bt[i];
    } 
    printf("\nEnter Time Quantum:\t"); 
    scanf("%d", &time_quantum); 
    printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
    for(total = 0, i = 0; x != 0;) 
    { 
        if(temp[i]<=time_quantum&&temp[i] > 0) 
        { 
            total = total + temp[i]; 
            temp[i] = 0; 
            counter = 1; 
        } 
        else if(temp[i] > 0) 
        { 
            temp[i] = temp[i] - time_quantum; 
            total = total + time_quantum; 
        } 
        if(temp[i] == 0 && counter == 1) 
        { 
            x--; 
            printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d",i + 1, bt[i], total-arr_time[i], total-arr_time[i]-bt[i]);
            wt = wt + total - arr_time[i] - bt[i]; 
            tat = tat + total - arr_time[i]; 
            counter = 0; 
        } 
        if(i == limit - 1) 
        {
            i = 0; 
        }
            else if(arr_time[i + 1] <= total) 
            {
                i++;
            }
            else 
            {
                i = 0;
            }
    } 
    avr_wt = wt * 1.0 / limit;
    avr_tat = tat * 1.0 / limit;
    printf("\n\nAverage Waiting Time:\t%f", avr_wt); 
    printf("\nAvg Turnaround Time:\t%f\n", avr_tat); 
    return 0; 
}
