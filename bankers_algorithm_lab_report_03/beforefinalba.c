#include <stdio.h>

int main() {
    int n, m; // n = number of processes, m = number of resources
    int i, j, k;

    // Input number of processes and resources
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    printf("Enter the number of resource types: ");
    scanf("%d", &m);

    int max[n][m], alloc[n][m], need[n][m], avail[m];
    int finish[n], safeSeq[n];

    // Input Max matrix
    printf("\nEnter the MAX matrix (Maximum demand for each process):\n");
    for (i = 0; i < n; i++) {
        printf("Process P%d: ", i);
        for (j = 0; j < m; j++)
            scanf("%d", &max[i][j]);
    }

    // Input Allocation matrix
    printf("\nEnter the Allocation matrix (Currently allocated resources):\n");
    for (i = 0; i < n; i++) {
        printf("Process P%d: ", i);
        for (j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);
    }

    // Input Available resources
    printf("\nEnter the Available resources for each type:\n");
    for (i = 0; i < m; i++) {
        printf("Resource R%d: ", i);
        scanf("%d", &avail[i]);
    }

    // Calculate Need matrix = Max - Allocation
    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    // Print matrices in table format
    printf("\nMAX Matrix:\n\t");
    for (j = 0; j < m; j++)
        printf("R%d ", j);
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t", i);
        for (j = 0; j < m; j++)
            printf("%d ", max[i][j]);
        printf("\n");
    }

    printf("\nAllocation Matrix:\n\t");
    for (j = 0; j < m; j++)
        printf("R%d ", j);
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t", i);
        for (j = 0; j < m; j++)
            printf("%d ", alloc[i][j]);
        printf("\n");
    }

    printf("\nNeed Matrix:\n\t");
    for (j = 0; j < m; j++)
        printf("R%d ", j);
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t", i);
        for (j = 0; j < m; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }

    // Initialize finish array to 0 (all processes unfinished)
    for (i = 0; i < n; i++)
        finish[i] = 0;

    int count = 0; // number of processes completed

    // Safety Algorithm
    while (count < n) {
        int found = 0; // check if a process can be completed
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) { // if process is not finished
                int canFinish = 1;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > avail[j]) {
                        canFinish = 0; // can't finish this process now
                        break;
                    }
                }
                if (canFinish) {
                    // Add allocation of this process to available
                    for (k = 0; k < m; k++)
                        avail[k] += alloc[i][k];
                    safeSeq[count++] = i; // add process to safe sequence
                    finish[i] = 1; // mark process as finished
                    found = 1;
                }
            }
        }
        if (!found) { // no process could be completed
            printf("\nSystem is UNSAFE! No safe sequence exists.\n");
            return 0;
        }
    }

    // Print Available resources after safety check
    printf("\nAvailable Resources after execution:\n");
    for (i = 0; i < m; i++)
        printf("R%d: %d  ", i, avail[i]);
    printf("\n");

    // Print Safe Sequence
    printf("\nSystem is SAFE.\nSafe Sequence: ");
    for (i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");

    return 0;
}
