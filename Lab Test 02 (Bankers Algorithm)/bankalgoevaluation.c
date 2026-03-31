// Shafin Ahmed_232-15-184_65-A1
//Banker's Algorithm

#include<stdio.h>
int main()
{
    int n,m;

    printf("enter total number of processes: ");
    scanf("%d",&n);
    printf("enter total number of resources: ");
    scanf("%d",&m);

//array related to resource
    int totalres[m]; //r1,r2,r3
    int available[m]; // currently available resources
    int work[m]; // Temporary array for checking safety
//tempo available resource track korar jonne

//process related matrices
    int max[n][m]; // maximum matrics
    int allocation[n][m]; // allocation matrics
    int need[n][m]; // max - allocation

    int safeseq[n]; //safe seq store korbe
    int finish[n]; //finish process track kore ...
//0= finish na, 1=finish

    int i,j,totalallocated;
    int count=0; //total num of finish process

//finish array init
    for(i=0; i<n; i++)
        finish[i]=0;

//input total resources
    printf("enter total instances of each resource:\n");
    for(i=0; i<m; i++)
    {
        printf("resource R%d: ",i+1);
        scanf("%d",&totalres[i]);
    }

//max matrix input
    printf("enter Max matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("Max for P%d, R%d: ", i, j + 1);
            scanf("%d", &max[i][j]);
        }
    }

// allocation matrix input
    printf("enter Allocation matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("Allocation for P%d, R%d: ", i, j + 1);
            scanf("%d", &allocation[i][j]);
        }
    }

//need matrix calculation
    for(i=0; i<n; i++)
    {
        for(j=0; j<m; j++)
        {
            need[i][j]=max[i][j]-allocation[i][j];
        }
    }

//calculating available
    for(i=0; i<m; i++)
    {
        totalallocated = 0;
//sum of all allocation for resource i
        for(j=0; j<n; j++)
        {
            totalallocated += allocation[j][i];
        }
        available[i] = totalres[i] - totalallocated;
// work initially same as available
        work[i] = available[i];
    }

//ekhon khali print hobe matrix gula
    printf("Allocation matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("%d ", allocation[i][j]);
        }
        printf("\n");
    }

    printf("Max matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("%d ", max[i][j]);
        }
        printf("\n");
    }

    printf("Need matrix:\n");
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < m; j++)
        {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    printf("Available resources: ");
    for(i = 0; i < m; i++)
    {
        printf("%d ", available[i]);
    }
    printf("\n");

    //Bankers Algorithm for Safety Check and the sequences

    while(count < n)
    {
        int found=0; //ei loop e kono process execute hoise kina check korbe

        for(i=0; i<n; i++)
        {
//not finish process check kore
            if(finish[i]==0)
            {
                int canexecute = 1;

//check need<=work
                for(j=0; j<m; j++)
                {
                    if(need[i][j]>work[j])
                    {
                        canexecute=0; //can't execute
                        break;
                    }
                }

//if process execute
                if(canexecute)
                {
//work er sathe allocated jog
                    for(j=0; j<m; j++)
                    {
                        work[j] += allocation[i][j];
                    }
//process finish er marking
                    safeseq[count++]=i;
                    finish[i]=1;
                    found = 1; // atleast ekta process execute hoilo
                }
            }
        }

//if no process execute than unsafe state
        if(found==0)
        {
            printf("System is not in safe state!\n");
            return 0;
        }
    }

//print Safe sequence
    printf("System is in Safe state.\nSafe sequence: ");
    for(i=0; i<n; i++)
    {
        printf("P%d ",safeseq[i]);
    }

    return 0;
}

/*
enter total number of processes: 5
enter total number of resources: 3
enter total instances of each resource:
resource R1: 7
resource R2: 5
resource R3: 10
enter Max matrix:
Max for P0, R1: 3
Max for P0, R2: 5
Max for P0, R3: 7
Max for P1, R1: 2
Max for P1, R2: 2
Max for P1, R3: 3
Max for P2, R1: 2
Max for P2, R2: 0
Max for P2, R3: 9
Max for P3, R1: 2
Max for P3, R2: 2
Max for P3, R3: 2
Max for P4, R1: 3
Max for P4, R2: 3
Max for P4, R3: 4
enter Allocation matrix:
Allocation for P0, R1: 0
Allocation for P0, R2: 1
Allocation for P0, R3: 0
Allocation for P1, R1: 0
Allocation for P1, R2: 0
Allocation for P1, R3: 2
Allocation for P2, R1: 2
Allocation for P2, R2: 0
Allocation for P2, R3: 3
Allocation for P3, R1: 1
Allocation for P3, R2: 1
Allocation for P3, R3: 2
Allocation for P4, R1: 2
Allocation for P4, R2: 0
Allocation for P4, R3: 0
Allocation matrix:
0 1 0
0 0 2
2 0 3
1 1 2
2 0 0
Max matrix:
3 5 7
2 2 3
2 0 9
2 2 2
3 3 4
Need matrix:
3 4 7
2 2 1
0 0 6
1 1 0
1 3 4
Available resources: 2 3 3
System is in Safe state.
Safe sequence: P1 P3 P4 P0 P2
Process returned 0 (0x0) execution time : 73.413 s
Press any key to continue.

*/
