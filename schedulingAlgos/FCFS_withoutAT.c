// FCFS algorithm without arrival time

#include<stdio.h>
int main()
{
    int n, i, j, k, temp, sum=0, wait=0, turn=0; // n is the number of processes, i, j, k are loop variables, temp is a temporary variable, sum is the sum of burst times, wait is the total waiting time, turn is the total turnaround time
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int bt[n], p[n], wt[n], tat[n]; // bt is the burst time, p is the process number, wt is the waiting time, tat is the turnaround time
    for(i=0; i<n; i++) // taking input
    {
        printf("Enter the burst time of process %d: ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i+1;
    }
    for(i=0; i<n; i++) // calculating the waiting time and turnarund time
    {
        sum = sum + bt[i];
        tat[i] = sum; // turnaround time = completion time
        wt[i] = tat[i] - bt[i]; // waiting time = turnaround time - burst time
        wait = wait + wt[i];
        turn = turn + tat[i];
    }
    printf("Process\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    printf("\nAverage waiting time: %f", (float)wait/n);
    printf("\nAverage turnaround time: %f\n", (float)turn/n);
    return 0;
}
