#include <stdio.h>

int main() {
    int pid[20], bt[20], at[20], wt[20], tat[20], ct[20];
    int n, completed = 0, time = 0, i, smallest;
    int visited[20] = {0};

    // Gantt chart store korar jonno
    int gantt[50], ganttTime[50];
    int gIndex = 0;

    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter Process IDs: ");
    for (i = 0; i < n; i++)
        scanf("%d", &pid[i]);

    printf("Enter Burst Times: ");
    for (i = 0; i < n; i++)
        scanf("%d", &bt[i]);

    printf("Enter Arrival Times: ");
    for (i = 0; i < n; i++)
        scanf("%d", &at[i]);

    // Main scheduling loop
    while (completed != n) {
        smallest = -1;

        // Ei loop diye check kortesi kon process ta ready ase
        for (i = 0; i < n; i++) {
            if (!visited[i] && at[i] <= time) {
                // shortest burst time wala process select
                if (smallest == -1 || bt[i] < bt[smallest]) {
                    smallest = i;
                }
            }
        }

        // Jodi kono process ekhono arrive na kore
        if (smallest == -1) {
            time++; // CPU idle thakbe
            continue;
        }

        // Gantt chart e process store
        gantt[gIndex] = pid[smallest];
        ganttTime[gIndex] = time;
        gIndex++;

        // Process execute kortesi
        time += bt[smallest];

        ct[smallest] = time; // completion time
        tat[smallest] = ct[smallest] - at[smallest]; // turnaround time
        wt[smallest] = tat[smallest] - bt[smallest]; // waiting time

        visited[smallest] = 1;
        completed++;
    }

    // Last time add (Gantt end time)
    ganttTime[gIndex] = time;

    // Output Table
    printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               pid[i], at[i], bt[i], ct[i], tat[i], wt[i]);

        avgWT += wt[i];
        avgTAT += tat[i];
    }

    avgWT /= n;
    avgTAT /= n;

    // Gantt Chart print
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