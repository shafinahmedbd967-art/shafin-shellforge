#include <stdio.h>

int main() {
    int n, m;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int totalRes[m], available[m], work[m];
    int max[n][m], allocation[n][m], need[n][m];
    int safeSeq[n], finish[n];

    for(int i = 0; i < n; i++)
        finish[i] = 0;

    printf("\nEnter total instances of each resource:\n");
    for(int i = 0; i < m; i++) {
        printf("Resource %c: ", 'A' + i);
        scanf("%d", &totalRes[i]);
    }

    printf("\nEnter MAX matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("Max for P%d, %c: ", i, 'A' + j);
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter ALLOCATION matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            printf("Allocation for P%d, %c: ", i, 'A' + j);
            scanf("%d", &allocation[i][j]);
        }
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            need[i][j] = max[i][j] - allocation[i][j];
    }

    for(int i = 0; i < m; i++) {
        int totalAllocated = 0;
        for(int j = 0; j < n; j++)
            totalAllocated += allocation[j][i];

        available[i] = totalRes[i] - totalAllocated;
        work[i] = available[i];
    }

    printf("\nAllocation Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            printf("%d ", allocation[i][j]);
        printf("\n");
    }

    printf("\nMax Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            printf("%d ", max[i][j]);
        printf("\n");
    }

    printf("\nNeed Matrix:\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            printf("%d ", need[i][j]);
        printf("\n");
    }

    printf("\nAvailable Resources: ");
    for(int i = 0; i < m; i++)
        printf("%d ", available[i]);
    printf("\n");

    int count = 0;
    while(count < n) {
        int found = 0;

        for(int i = 0; i < n; i++) {
            if(finish[i] == 0) {
                int canExecute = 1;

                for(int j = 0; j < m; j++) {
                    if(need[i][j] > work[j]) {
                        canExecute = 0;
                        break;
                    }
                }

                if(canExecute) {
                    for(int j = 0; j < m; j++)
                        work[j] += allocation[i][j];

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(found == 0) {
            printf("\nSystem is NOT in safe state!\n");
            return 0;
        }
    }

    printf("\nSystem is in SAFE state.\nSafe sequence: ");
    for(int i = 0; i < n; i++)
        printf("P%d ", safeSeq[i]);
    printf("\n");

    return 0;
}