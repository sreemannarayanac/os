# Scheduling Algorithms
## Algorithms covered
1. FCFS (First Come First Serve)
2. SJF (Shortest Job First)
3. Round Robin
4. Priority Scheduling

## 1. FCFS (First Come First Serve)
- The simplest scheduling algorithm.
- The process that arrives first is executed first.
- It is a non-preemptive algorithm.
- Code for FCFS in C with explanation:
```c
#include<stdio.h>
int main()
{
    int n, i, j, k, temp, sum=0, wait=0, turn=0; // n is the number of processes, i, j, k are loop variables, temp is a temporary variable, sum is the sum of burst times, wait is the total waiting time, turn is the total turnaround time
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int bt[n], at[n], p[n], wt[n], tat[n]; // bt is the burst time, at is the arrival time, p is the process number, wt is the waiting time, tat is the turnaround time
    for(i=0; i<n; i++) // taking input
    {
        printf("Enter the arrival time of process %d: ", i+1);
        scanf("%d", &at[i]);
        printf("Enter the burst time of process %d: ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i+1;
    }
    for(i=0; i<n; i++) // sorting the processes according to their arrival time
    {
        for(j=i+1; j<n; j++)
        {
            if(at[i]>at[j])
            {
                temp = at[i];
                at[i] = at[j];
                at[j] = temp;
                temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;
                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
    for(i=0; i<n; i++) // calculating the waiting time and turnarund time
    {
        sum = sum + bt[i];
        tat[i] = sum - at[i]; // turnaround time = completion time - arrival time
        wt[i] = tat[i] - bt[i]; // waiting time = turnaround time - burst time
        wait = wait + wt[i];
        turn = turn + tat[i];
    }
    printf("Process\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for(i=0; i<n; i++)
    {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\n", p[i], at[i], bt[i], wt[i], tat[i]);
    }
    printf("Average waiting time: %f\n", (float)wait/n);
    printf("Average turnaround time: %f\n", (float)turn/n);
    return 0;
}
```
- Output:
```
Enter the number of processes: 3
Enter the arrival time of process 1: 0
Enter the burst time of process 1: 5
Enter the arrival time of process 2: 1
Enter the burst time of process 2: 4
Enter the arrival time of process 3: 2
Enter the burst time of process 3: 3
Process	Arrival Time	Burst Time	Waiting Time	Turnaround Time
1	0		5		0		5
2	1		4		4		8
3	2		3		7		10
Average waiting time: 3.666667
Average turnaround time: 7.666667
```