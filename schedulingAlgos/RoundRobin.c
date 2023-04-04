#include <stdio.h>

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

    printf("\nEnter the time quantum: ");
    scanf("%d", &quant);

    printf("\nProcess No\tBurst Time\tTAT\t\tWaiting Time\n");

    for (sum = 0, i = 0; y != 0;) { // initializes sum to zero and i to zero, y is used to check whether the process is completed or not
        if (temp[i] <= quant && temp[i] > 0) { // If burst time is less than or equal to time quantum
            sum = sum + temp[i]; // Add burst time to sum
            temp[i] = 0; // here temp variable is used to store the remaining burst time
            count = 1; // count is used to check whether the process is completed or not
        } else if (temp[i] > 0) { // If burst time is greater than time quantum
            temp[i] = temp[i] - quant; // Subtract time quantum from burst time
            sum = sum + quant; // Add time quantum to sum
        }
        if (temp[i] == 0 && count == 1) {
            y--; // Decrement the number of processes, this results in the process being completed and for loop to terminate
            printf("%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);
            wt = wt + sum - at[i] - bt[i];
            tat = tat + sum - at[i];
            count = 0;
        }
        if (i == NOP - 1) { // sets index to zero if it reaches the end of the array and the process is not completed
            i = 0;
        } else if (at[i + 1] <= sum) { // if the arrival time of the next process is less than or equal to the sum
            i++;
        } else { // if the arrival time of the next process is greater than the sum, it results in the process being idle as it has to wait for the next process to arrive
            i = 0;
        }
    }

    avg_wt = (float) wt / NOP;
    avg_tat = (float) tat / NOP;

    printf("\nAverage waiting time: %f", avg_wt);
    printf("\nAverage turnaround time: %f\n", avg_tat);
}
