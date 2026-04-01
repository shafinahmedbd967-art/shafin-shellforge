#include <stdio.h>

int main()
{
    int n, i, completed = 0;
    float time = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], done[n];

    float at[n], bt[n], ft[n], tat[n], wt[n];

    // Input nitesi
    for(i = 0; i < n; i++)
    {
        printf("\nProcess P%d\n", i + 1);

        pid[i] = i + 1;

        printf("Enter Arrival Time: ");
        scanf("%f", &at[i]);

        printf("Enter Burst Time: ");
        scanf("%f", &bt[i]);

        done[i] = 0; // process ekhono complete hoy nai
    }

    float total_tat = 0, total_wt = 0;

    // SJF Non-preemptive main logic
    while(completed < n)
    {
        int min_index = -1;

        // ready process der moddhe smallest BT khujtesi
        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && done[i] == 0)
            {
                if(min_index == -1 || bt[i] < bt[min_index])
                {
                    min_index = i;
                }
            }
        }

        // jodi kono process ready na thake
        if(min_index == -1)
        {
            time++; // CPU idle
        }
        else
        {
            // process execute kortesi
            ft[min_index] = time + bt[min_index];

            tat[min_index] = ft[min_index] - at[min_index];
            wt[min_index] = tat[min_index] - bt[min_index];

            total_tat += tat[min_index];
            total_wt += wt[min_index];

            time = ft[min_index]; // time update

            done[min_index] = 1;
            completed++;
        }
    }

    // Output table
    printf("\n\nProcess\tAT\tBT\tFT\tTAT\tWT\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%.1f\t%.1f\t%.1f\t%.1f\t%.1f\n",
               pid[i], at[i], bt[i], ft[i], tat[i], wt[i]);
    }

    // Average
    printf("\nAverage Turnaround Time = %.2f", total_tat / n);
    printf("\nAverage Waiting Time = %.2f\n", total_wt / n);

    // Gantt Chart generate kortesi
    printf("\nGantt Chart:\n\n|");

    int temp_done[n];
    for(i = 0; i < n; i++) temp_done[i] = 0;

    float gantt_time[n+1];
    int k = 0;

    time = 0;
    completed = 0;

    // start time
    gantt_time[k++] = time;

    while(completed < n)
    {
        int min_index = -1;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && temp_done[i] == 0)
            {
                if(min_index == -1 || bt[i] < bt[min_index])
                {
                    min_index = i;
                }
            }
        }

        if(min_index == -1)
        {
            time++;
        }
        else
        {
            printf(" P%d |", pid[min_index]);

            time += bt[min_index];
            gantt_time[k++] = time;

            temp_done[min_index] = 1;
            completed++;
        }
    }

    printf("\n");

    // timeline print
    for(i = 0; i < k; i++)
    {
        printf("%.1f\t", gantt_time[i]);
    }

    printf("\n");

    return 0;
}

/*
Problem: SJF (Non-Preemptive Scheduling)

Description:
SJF mane Shortest Job First.
Je process er Burst Time sobcheye kom, she age execute hoy.

Non-preemptive mane:
Ekbar process start hole sesh na howa porjonto interrupt kora jabe na.

Steps:
1) Ready queue theke smallest BT process select
2) Execute full
3) Next smallest BT

Condition:
- arrival time <= current time holei process ready
- na hole CPU idle

Formula:
FT = Finish Time
TAT = FT - AT
WT = TAT - BT

Input:
Process, Arrival Time, Burst Time

Output:
Process Table + Gantt Chart + Average WT & TAT

Sample Input:
3
P1: AT=0 BT=5
P2: AT=1 BT=3
P3: AT=2 BT=1

Sample Output:

Process AT  BT  FT  TAT WT
P1      0   5   5   5   0
P3      2   1   6   4   3
P2      1   3   9   8   5

Gantt Chart:
| P1 | P3 | P2 |

0     5     6     9

Explanation:
Time 0 → only P1 → run
Time 5 → P2,P3 ready → P3 shortest → run
Time 6 → P2 run
*/