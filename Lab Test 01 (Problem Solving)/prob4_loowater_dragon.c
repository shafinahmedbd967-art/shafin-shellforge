#include <stdio.h>
#include <stdlib.h>

// sort er jonno compare function
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int n, m;

    while(1) {
        scanf("%d %d", &n, &m);

        // input end condition
        if(n == 0 && m == 0)
            break;

        int head[20005], knight[20005];

        // dragon head diameter input
        for(int i = 0; i < n; i++)
            scanf("%d", &head[i]);

        // knight height input
        for(int i = 0; i < m; i++)
            scanf("%d", &knight[i]);

        // greedy er jonno sort kora dorkar
        qsort(head, n, sizeof(int), cmp);
        qsort(knight, m, sizeof(int), cmp);

        int i = 0, j = 0;
        int cost = 0;

        // i = head pointer
        // j = knight pointer
        while(i < n && j < m) {

            // jodi knight enough tall hoy
            if(knight[j] >= head[i]) {
                cost += knight[j]; // oi knight er height = cost
                i++; // next head
                j++; // next knight
            } else {
                j++; // ei knight useless, next knight dekhi
            }
        }

        // jodi sob head cut hoy
        if(i == n) {
            printf("%d\n", cost);
        } else {
            printf("Loowater is doomed!\n");
        }
    }

    return 0;
}

/*
Problem: Dragon of Loowater

Description:
Ekta dragon ase jar multiple head ase.
Prottek head er diameter ase.

Knight gula ase jader height ase.
Ekta knight sudhu ekta head cut korte parbe.

Condition:
Knight height >= head diameter hole oi knight oi head cut korte parbe.

Cost:
Prottek knight er height = tar cost (gold coin)

Goal:
Sob head cut korte hobe minimum total cost e.

Jodi possible na hoy → "Loowater is doomed!"

Greedy Idea:
- sob head sort (small → big)
- sob knight sort (small → big)
- smallest head er jonno smallest possible knight use

Input:
n m
n ta head diameter
m ta knight height
0 0 hole end

Output:
minimum cost OR "Loowater is doomed!"

Sample Input:
2 3
5
4
7
8
4
2 1
5
5
10
0 0

Sample Output:
11
Loowater is doomed!

Explanation:
Case 1:
Head: 4,5
Knight: 7,8,4

4 → 4 diye cut
5 → 7 diye cut
Total = 4 + 7 = 11

Case 2:
Head: 5,5
Knight: 10

1 ta knight diye 2 ta head possible na → doomed
*/