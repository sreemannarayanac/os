#include <stdio.h>

int main()
{
    printf("Enter number of processes: ");
    int n; scanf("%d", &n);
    int p[n], bt[n], pr[n], ct[n], wt[n], tat[n];

    printf("Input burst time and priority for each process: ");
    for (int i=0; i<n; i++) {
        printf("\nEnter process %d details", i+1);
        printf("\nBurst time: "); scanf("%d", &bt[i]);
        printf("Priority: "); scanf("%d", &pr[i]);
        p[i] = i+1;
    } 

    // sort processes by priority
    //! Less priority number is better
    for(int i=0; i<n; i++) {
        for(int j=i; j<n; j++) {
            if (pr[i] > pr[j]) {
                int temp = pr[i]; // swapping priority
                pr[i] = pr[j];
                pr[j] = temp;

                temp = bt[i]; // swapping burst time
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i]; // swapping process number
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    // calculating completion time, waiting time and turnaround time
    ct[0] = bt[0];
    wt[0] = 0;
    tat[0] = bt[0];
    int tot_tat = tat[0];
    int tot_wt = wt[0];
    for(int i=1; i<n; i++) {
        ct[i] = ct[i-1] + bt[i];
        wt[i] = ct[i] - bt[i];
        tat[i] = ct[i];
        tot_tat += tat[i];
        tot_wt += wt[i];
    }

    // printing the table
    printf("Process\tBurst Time\tPriority\tCompletion Time\t\tWaiting Time\tTurnaround Time");
    for (int i=0; i<n; i++) {
        printf("\n%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", p[i], bt[i], pr[i], ct[i], wt[i], tat[i]);
    }
    printf("\nAverage waiting time: %f", (float)tot_wt/n);
    printf("\nAverage turnaround time: %f\n", (float)tot_tat/n);
}