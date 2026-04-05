// Shafin Ahmed  232-15-184  65-A1

#include <stdio.h>

int main()
{
    int n, i, completed = 0;
    float time = 0;

    printf("\n========================================\n");
    printf("     SJF Scheduling (Non-Preemptive)\n");
    printf("========================================\n");

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int pid[n], done[n];
    float at[n], bt[n], ft[n], tat[n], wt[n];

    // Input Section
    printf("\n--------- Input Section ---------\n");
    for(i = 0; i < n; i++)
    {
        printf("\nProcess P%d\n", i + 1);

        pid[i] = i + 1;

        printf("Arrival Time : ");
        scanf("%f", &at[i]);

        printf("Burst Time   : ");
        scanf("%f", &bt[i]);

        done[i] = 0;
    }

    float total_tat = 0, total_wt = 0;

    // SJF Logic
    while(completed < n)
    {
        int min_index = -1;

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

        if(min_index == -1)
        {
            time++;
        }
        else
        {
            ft[min_index] = time + bt[min_index];
            tat[min_index] = ft[min_index] - at[min_index];
            wt[min_index] = tat[min_index] - bt[min_index];

            total_tat += tat[min_index];
            total_wt += wt[min_index];

            time = ft[min_index];

            done[min_index] = 1;
            completed++;
        }
    }

    // Output Table
    printf("\n\n========================================\n");
    printf("            Result Table\n");
    printf("========================================\n");

    printf("\n%-8s %-8s %-8s %-8s %-8s %-8s\n",
           "Process", "AT", "BT", "FT", "TAT", "WT");

    printf("--------------------------------------------------------\n");

    for(i = 0; i < n; i++)
    {
        printf("P%-7d %-8.1f %-8.1f %-8.1f %-8.1f %-8.1f\n",
               pid[i], at[i], bt[i], ft[i], tat[i], wt[i]);
    }

    printf("--------------------------------------------------------\n");

    printf("\nAverage Turnaround Time : %.2f\n", total_tat / n);
    printf("Average Waiting Time    : %.2f\n", total_wt / n);

    // Gantt Chart
    printf("\n========================================\n");
    printf("            Gantt Chart\n");
    printf("========================================\n\n");

    int temp_done[n];
    for(i = 0; i < n; i++) temp_done[i] = 0;

    float gantt_time[n+1];
    int k = 0;
    time = 0;
    completed = 0;

    gantt_time[k++] = time;

    printf("|");

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
            printf("  P%d  |", pid[min_index]);
            time += bt[min_index];
            gantt_time[k++] = time;

            temp_done[min_index] = 1;
            completed++;
        }
    }

    printf("\n");

    for(i = 0; i < k; i++)
    {
        printf("%-6.1f", gantt_time[i]);
    }

    printf("\n\n========================================\n");

    return 0;
}