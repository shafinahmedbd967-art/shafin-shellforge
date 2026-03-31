#include <stdio.h>

int main() {
    int totalRes[3], available[3], work[3];
    int max[5][3], allocation[5][3], need[5][3];
    int safeSeq[5];
    int finish[5] = {0};   // 0 = false, 1 = true

    int i, j, k;
    int totalAllocated, count = 0;

    // 🔹 Step 1: Input total resources
    printf("Enter total instances of 3 resources:\n");
    for(i = 0; i < 3; i++) {
        scanf("%d", &totalRes[i]);
    }

    // 🔹 Step 2: Input Max matrix
    printf("\nEnter MAX matrix:\n");
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 3; j++) {
            printf("Max for P%d, R%d: ", i, j+1);
            scanf("%d", &max[i][j]);
        }
    }

    // 🔹 Step 3: Input Allocation matrix
    printf("\nEnter ALLOCATION matrix:\n");
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 3; j++) {
            printf("Allocation for P%d, R%d: ", i, j+1);
            scanf("%d", &allocation[i][j]);
        }
    }

    // 🔹 Step 4: Calculate NEED matrix
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 3; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // 🔹 Step 5: Calculate AVAILABLE resources
    for(i = 0; i < 3; i++) {
        totalAllocated = 0;
        for(j = 0; j < 5; j++) {
            totalAllocated += allocation[j][i];
        }
        available[i] = totalRes[i] - totalAllocated;
        work[i] = available[i];
    }

    // 🔹 Step 6: Print matrices
    printf("\nAllocation Matrix:\n");
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", allocation[i][j]);
        }
        printf("\n");
    }

    printf("\nMax Matrix:\n");
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }

    printf("\nNeed Matrix:\n");
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 3; j++) {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    printf("\nAvailable Resources: ");
    for(i = 0; i < 3; i++) {
        printf("%d ", available[i]);
    }
    printf("\n");

    // 🔹 Step 7: Banker's Algorithm (Safety Check)
    while(count < 5) {
        int found = 0;

        for(i = 0; i < 5; i++) {
            if(finish[i] == 0) {
                int canExecute = 1;

                for(j = 0; j < 3; j++) {
                    if(need[i][j] > work[j]) {
                        canExecute = 0;
                        break;
                    }
                }

                // If process can execute
                if(canExecute) {
                    for(j = 0; j < 3; j++) {
                        work[j] += allocation[i][j];
                    }

                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        // If no process found → unsafe state
        if(found == 0) {
            printf("\nSystem is NOT in safe state!\n");
            return 0;
        }
    }

    // 🔹 Step 8: Print Safe Sequence
    printf("\nSystem is in SAFE state.\nSafe sequence: ");
    for(i = 0; i < 5; i++) {
        printf("P%d ", safeSeq[i]);
    }

    return 0;
}
