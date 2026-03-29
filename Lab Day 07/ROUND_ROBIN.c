#include <stdio.h>

int main() {
    int n, tq;
    int at[10], bt[10], rt[10], ct[10], tat[10], wt[10];
    int queue[100], front = 0, rear = 0;
    int time = 0, completed = 0;
    int i, j;

    int visited[10] = {0}; // queue te dhukse kina check
    int done[10] = {0};    // process complete hoise kina

    // Gantt chart er jonno
    int gantt[100], ganttTime[100];
    int gIndex = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input nitesi
    for (i = 0; i < n; i++) {
        printf("Enter AT & BT for P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i]; // remaining time initially = burst time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    //  First arrival process ber kortesi
    int first = 0;
    for (i = 1; i < n; i++) {
        if (at[i] < at[first]) {
            first = i;
        }
    }

    time = at[first];
    queue[rear++] = first;
    visited[first] = 1;

    printf("\nGantt Chart:\n|");

    //  Main Round Robin loop
    while (completed < n) {

        // Jodi queue empty hoye jai
        if (front == rear) {
            for (i = 0; i < n; i++) {
                if (!done[i]) {
                    time = at[i]; // jump to next arrival
                    queue[rear++] = i;
                    visited[i] = 1;
                    break;
                }
            }
        }

        i = queue[front++]; // dequeue

        // Gantt e store start time
        gantt[gIndex] = i + 1;
        ganttTime[gIndex] = time;
        gIndex++;

        //  Execution logic
        if (rt[i] > tq) {
            time += tq;
            rt[i] -= tq;
        } else {
            time += rt[i];
            ct[i] = time;
            tat[i] = ct[i] - at[i];
            wt[i] = tat[i] - bt[i];

            rt[i] = 0;
            done[i] = 1;
            completed++;
        }

        // Notun process gula enqueue
        for (j = 0; j < n; j++) {
            if (at[j] <= time && rt[j] > 0 && !visited[j]) {
                queue[rear++] = j;
                visited[j] = 1;
            }
        }

        // Jodi current process sesh na hoy
        if (rt[i] > 0) {
            queue[rear++] = i;
        }
    }

    // Last time add
    ganttTime[gIndex] = time;

    //  Gantt Chart print
    for (i = 0; i < gIndex; i++) {
        printf(" P%d |", gantt[i]);
    }

    printf("\n%d", ganttTime[0]);
    for (i = 1; i <= gIndex; i++) {
        printf("    %d", ganttTime[i]);
    }

    //  Table print
    float avgWT = 0, avgTAT = 0;

    printf("\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);

        avgWT += wt[i];
        avgTAT += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", avgWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", avgTAT / n);

    return 0;
}