#include <stdio.h>

int main() {
    int n, m;

    // ================================
    // 🔹 Step 0: Input number of processes & resources
    // ================================
    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    // 🔹 Resource related arrays
    int totalRes[m];    // Total resources in system (A, B, C, ...)
    int available[m];   // Currently available resources
    int work[m];        // Temporary array used in safety check

    // 🔹 Process related matrices
    int max[n][m];       // Maximum demand of each process
    int allocation[n][m];// Resources already allocated
    int need[n][m];      // Remaining need = max - allocation

    int safeSeq[n];      // To store safe sequence
    int finish[n];       // Track finished processes (0 = not finished, 1 = finished)

    int i, j, totalAllocated;
    int count = 0;       // Number of finished processes

    // Initialize finish array
    for(i = 0; i < n; i++) finish[i] = 0;

    // ================================
    // 🔹 Step 1: Input total resources
    // ================================
    printf("\nEnter total instances of each resource:\n");
    for(i = 0; i < m; i++) {
        printf("Resource %c: ", 'A' + i);
        scanf("%d", &totalRes[i]);
    }

    // ================================
    // 🔹 Step 2: Input MAX matrix
    // ================================
    printf("\nEnter MAX matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("Max for P%d, %c: ", i, 'A' + j);
            scanf("%d", &max[i][j]);
        }
    }

    // ================================
    // 🔹 Step 3: Input ALLOCATION matrix
    // ================================
    printf("\nEnter ALLOCATION matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            printf("Allocation for P%d, %c: ", i, 'A' + j);
            scanf("%d", &allocation[i][j]);
        }
    }

    // ================================
    // 🔹 Step 4: Calculate NEED matrix
    // ================================
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // ================================
    // 🔹 Step 5: Calculate AVAILABLE
    // ================================
    for(i = 0; i < m; i++) {
        totalAllocated = 0;
        for(j = 0; j < n; j++) totalAllocated += allocation[j][i];
        available[i] = totalRes[i] - totalAllocated;
        work[i] = available[i];
    }

    // ================================
    // 🔹 Step 6: Print matrices
    // ================================
    printf("\nAllocation Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) printf("%d ", allocation[i][j]);
        printf("\n");
    }

    printf("\nMax Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) printf("%d ", max[i][j]);
        printf("\n");
    }

    printf("\nNeed Matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < m; j++) printf("%d ", need[i][j]);
        printf("\n");
    }

    printf("\nAvailable Resources: ");
    for(i = 0; i < m; i++) printf("%d ", available[i]);
    printf("\n");

    // ================================
    // 🔹 Step 7: Banker's Algorithm (Safety Check)
    // ================================
    while(count < n) {
        int found = 0;

        for(i = 0; i < n; i++) {
            if(finish[i] == 0) {
                int canExecute = 1;

                for(j = 0; j < m; j++) {
                    if(need[i][j] > work[j]) {
                        canExecute = 0;
                        break;
                    }
                }

                if(canExecute) {
                    for(j = 0; j < m; j++) work[j] += allocation[i][j];
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

    // ================================
    // 🔹 Step 8: Print Safe Sequence
    // ================================
    printf("\nSystem is in SAFE state.\nSafe sequence: ");
    for(i = 0; i < n; i++) printf("P%d ", safeSeq[i]);
    printf("\n");

    return 0;
}