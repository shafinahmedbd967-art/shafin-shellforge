#include <stdio.h>

int main() {
    int n, i, j;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n];
    float at[n], bt[n], ft[n], tat[n], wt[n];

    // Input nitesi
    for(i = 0; i < n; i++) {
        printf("\nProcess P%d\n", i + 1);

        pid[i] = i + 1;

        printf("Enter Arrival Time: ");
        scanf("%f", &at[i]);

        printf("Enter Burst Time: ");
        scanf("%f", &bt[i]);
    }

    // FCFS rule: arrival time onujai sort kortesi
    for(i = 0; i < n - 1; i++) {
        for(j = i + 1; j < n; j++) {

            if(at[i] > at[j]) {

                // AT swap
                float temp;
                temp = at[i]; at[i] = at[j]; at[j] = temp;

                // BT swap
                temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;

                // PID swap
                int t;
                t = pid[i]; pid[i] = pid[j]; pid[j] = t;
            }
        }
    }

    // Finish Time calculate kortesi
    ft[0] = at[0] + bt[0];

    for(i = 1; i < n; i++) {

        // jodi CPU idle thake (gap thake)
        if(ft[i-1] < at[i])
            ft[i] = at[i] + bt[i];
        else
            ft[i] = ft[i-1] + bt[i];
    }

    float total_tat = 0, total_wt = 0;

    // TAT & WT calculate
    for(i = 0; i < n; i++) {
        tat[i] = ft[i] - at[i];
        wt[i] = tat[i] - bt[i];

        total_tat += tat[i];
        total_wt += wt[i];
    }

    // Table print
    printf("\n\nProcess\tAT\tBT\tFT\tTAT\tWT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",
               pid[i], at[i], bt[i], ft[i], tat[i], wt[i]);
    }

    // Average
    printf("\nAverage Turnaround Time = %.2f", total_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);

    // Gantt Chart print
    printf("\nGantt Chart:\n\n|");

    for(i = 0; i < n; i++) {
        printf("  P%d  |", pid[i]);
    }

    printf("\n");

    // Time line print
    printf("%.1f", at[0]);
    for(i = 0; i < n; i++) {
        printf("     %.1f", ft[i]);
    }

    printf("\n");

    return 0;
}

/*
Problem: FCFS (First Come First Serve) Scheduling

Description:
FCFS holo CPU scheduling algorithm jekhane
je process age ashe (arrival time kom), she age execute hoy.

Steps:
1) Process gula ke arrival time onujai sort korte hoy
2) Prothom process directly execute hoy
3) Next process wait kore ager process finish howa porjonto
4) Jodi gap thake (CPU idle), tahole arrival time theke start

Formula:
FT = Finish Time
TAT = FT - AT
WT = TAT - BT

Input:
Process number
Arrival Time (AT)
Burst Time (BT)

Output:
Table:
PID AT BT FT TAT WT
+ Gantt Chart
+ Average TAT & WT

Sample Input:
3
P1: AT=0 BT=5
P2: AT=2 BT=3
P3: AT=4 BT=1

Sample Output:

Process AT  BT  FT  TAT WT
P1      0   5   5   5   0
P2      2   3   8   6   3
P3      4   1   9   5   4

Gantt Chart:
| P1 | P2 | P3 |

0     5     8     9

Explanation:
P1 → 0-5
P2 → 5-8
P3 → 8-9
*/