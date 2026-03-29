#include <stdio.h>

int main() {
    int pid[20], bt[20], at[20], wt[20], tat[20], ct[20];
    int n, i;

    // Gantt chart er jonno
    int gantt[50], ganttTime[50];
    int gIndex = 0;

    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Process IDs: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pid[i]);

    printf("Enter Arrival Times: ");
    for (i = 0; i < n; i++)
        scanf("%d", &at[i]);

    printf("Enter Burst Times: ");
    for (i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    //  FCFS e normally arrival time onujai sort korte hoy
    // Simple bubble sort use kortesi
    for (i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                // swap AT
                int temp = at[j];
                at[j] = at[j + 1];
                at[j + 1] = temp;

                // swap BT
                temp = bt[j];
                bt[j] = bt[j + 1];
                bt[j + 1] = temp;

                // swap PID
                temp = pid[j];
                pid[j] = pid[j + 1];
                pid[j + 1] = temp;
            }
        }
    }

    int time = 0;

    //  Main FCFS logic
    for (i = 0; i < n; i++) {

        // Jodi CPU idle thake (process deri te ashe)
        if (time < at[i]) {
            time = at[i];
        }

        // Gantt chart e store kortesi
        gantt[gIndex] = pid[i];
        ganttTime[gIndex] = time;
        gIndex++;

        // Process execute
        time += bt[i];

        ct[i] = time; // completion time
        tat[i] = ct[i] - at[i]; // turnaround time
        wt[i] = tat[i] - bt[i]; // waiting time
    }

    // Last time (end time)
    ganttTime[gIndex] = time;

    //  Table print
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);

        avgWT += wt[i];
        avgTAT += tat[i];
    }

    avgWT /= n;
    avgTAT /= n;

    //  Gantt Chart print
    printf("\nGantt Chart:\n|");
    for (i = 0; i < gIndex; i++) {
        printf(" P%d |", gantt[i]);
    }

    printf("\n%d", ganttTime[0]);
    for (i = 1; i <= gIndex; i++) {
        printf("    %d", ganttTime[i]);
    }

    printf("\n");

    printf("\nAverage Waiting Time: %.2f", avgWT);
    printf("\nAverage Turnaround Time: %.2f\n", avgTAT);

    return 0;
}