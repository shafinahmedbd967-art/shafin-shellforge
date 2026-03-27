#include <stdio.h>

int main() {

    // 🔹 Resource related arrays
    int totalRes[3];     // Total resources in system (R1, R2, R3)
    int available[3];    // Currently available resources
    int work[3];         // Temporary array (used in safety algorithm)
                         // To track temporary avalable resource
                          
    // 🔹 Process related matrices
    int max[5][3];        // Maximum demand of each process
    int allocation[5][3]; // Resources already allocated
    int need[5][3];       // Remaining need = max - allocation

    int safeSeq[5];       // To store safe sequence
    int finish[5] = {0};  // Track finished processes (0 = not finished, 1 = finished)

    int i, j;
    int totalAllocated;
    int count = 0;        // Number of processes finished

    // ================================
    // 🔹 Step 1: Input total resources
    // ================================
    printf("Enter total instances of 3 resources:\n");
    for(i = 0; i < 3; i++) {
        scanf("%d", &totalRes[i]);  
        // Example: 10 5 7
    }

    // ================================
    // 🔹 Step 2: Input MAX matrix
    // ================================
    printf("\nEnter MAX matrix:\n");
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 3; j++) {
            printf("Max for P%d, R%d: ", i, j+1);
            scanf("%d", &max[i][j]);
        }
    }

    // ================================
    // 🔹 Step 3: Input ALLOCATION matrix
    // ================================
    printf("\nEnter ALLOCATION matrix:\n");
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 3; j++) {
            printf("Allocation for P%d, R%d: ", i, j+1);
            scanf("%d", &allocation[i][j]);
        }
    }

    // ================================
    // 🔹 Step 4: Calculate NEED matrix
    // NEED = MAX - ALLOCATION
    // ================================
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 3; j++) {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    // ================================
    // 🔹 Step 5: Calculate AVAILABLE
    // Available = Total - Allocated
    // ================================
    for(i = 0; i < 3; i++) {
        totalAllocated = 0;

        // Sum of all allocation for resource i
        for(j = 0; j < 5; j++) {
            totalAllocated += allocation[j][i];
        }

        available[i] = totalRes[i] - totalAllocated;

        // work initially same as available
        work[i] = available[i];
    }

    // ================================
    // 🔹 Step 6: Print matrices
    // ================================
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

    // ============================================
    // 🔹 Step 7: Banker's Algorithm (Safety Check)
    // ============================================

    while(count < 5) {   // Loop until all processes finish
        int found = 0;   // Check if any process executed in this loop

        for(i = 0; i < 5; i++) {

            // Only check unfinished processes
            if(finish[i] == 0) {

                int canExecute = 1;

                // Check if NEED <= WORK
                for(j = 0; j < 3; j++) {
                    if(need[i][j] > work[j]) {
                        canExecute = 0;  // Can't execute
                        break;
                    }
                }

                // ✅ If process can execute
                if(canExecute) {

                    // Add its allocated resources back to work
                    for(j = 0; j < 3; j++) {
                        work[j] += allocation[i][j];
                    }

                    // Mark process as finished
                    safeSeq[count++] = i;
                    finish[i] = 1;

                    found = 1;  // At least one process executed
                }
            }
        }

        // ❌ যদি কোনো process execute না হয় → Unsafe state
        if(found == 0) {
            printf("\nSystem is NOT in safe state!\n");
            return 0;
        }
    }

    // ================================
    // 🔹 Step 8: Print Safe Sequence
    // ================================
    printf("\nSystem is in SAFE state.\nSafe sequence: ");
    for(i = 0; i < 5; i++) {
        printf("P%d ", safeSeq[i]);
    }

    return 0;
}