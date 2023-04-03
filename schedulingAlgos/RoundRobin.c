#include <stdio.h>

void printTable(int at[], int bt[], int wt[], int tat[], int n) {
    printf("\nProcess No\tArrival Time\tBurst Time\tTAT\t\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, at[i], bt[i], tat[i], wt[i]);
    }
}

void main() {
    int i, NOP, sum = 0, count = 0, y, quant, wt = 0, tat = 0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;
    printf("Total number of processes in the system: ");
    scanf("%d", &NOP);
    y = NOP;

    for (i = 0; i < NOP; i++) {
        printf("\nEnter the arrival and burst time of process[%d]:\n", i + 1);
        printf("Arrival time: ");
        scanf("%d", &at[i]);
        printf("Burst time: ");
        scanf("%d", &bt[i]);
        temp[i] = bt[i];
    }

    printf("Enter the time quantum: ");
    scanf("%d", &quant);

    printf("\nProcess No\tBurst Time\tTAT\t\tWaiting Time\n");

    for (sum = 0, i = 0; y != 0;) {
        if (temp[i] <= quant && temp[i] > 0) {
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        } else if (temp[i] > 0) {
            temp[i] = temp[i] - quant;
            sum = sum + quant;
        }
        if (temp[i] == 0 && count == 1) {
            y--;
            printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);
            wt = wt + sum - at[i] - bt[i];
            tat = tat + sum - at[i];
            count = 0;
        }
        if (i == NOP - 1) {
            i = 0;
        } else if (at[i + 1] <= sum) {
            i++;
        } else {
            i = 0;
        }
    }

    avg_wt = (float) wt / NOP;
    avg_tat = (float) tat / NOP;

    printf("\nAverage waiting time: %f", avg_wt);
    printf("\nAverage turnaround time: %f", avg_tat);

    printTable(at, bt, wt, tat, NOP);
}
