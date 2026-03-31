#include <stdio.h>

// binary search diye just smaller ber korbo
int findShorter(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    int ans = -1; // jodi na pai

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] < key) {
            ans = arr[mid]; // candidate
            low = mid + 1;  // aro boro kisu ase kina dekhi
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

// binary search diye just taller ber korbo
int findTaller(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    int ans = -1;

    while(low <= high) {
        int mid = (low + high) / 2;

        if(arr[mid] > key) {
            ans = arr[mid]; // candidate
            high = mid - 1; // aro choto taller ase kina dekhi
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n, q;
    int arr[50000];

    // number of lady chimps
    scanf("%d", &n);

    // sorted height input
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // number of queries
    scanf("%d", &q);

    while(q--) {
        int h;
        scanf("%d", &h); // luchu er height

        int shorter = findShorter(arr, n, h);
        int taller  = findTaller(arr, n, h);

        // jodi na pai tahole X print
        if(shorter == -1)
            printf("X ");
        else
            printf("%d ", shorter);

        if(taller == -1)
            printf("X\n");
        else
            printf("%d\n", taller);
    }

    return 0;
}

/*
Problem: Luchu Bandor and Lady Chimps

Description (short):
Ekta sorted list ase lady chimp der height niye.
Prottek query te Luchu er height deya thakbe.
Toke 2 ta value ber korte hobe:
1) tar theke choto maximum height
2) tar theke boro minimum height

Same height consider kora jabe na.

Jodi kono value na thake tahole X print korte hobe.

Input Format:
N
N ta sorted height
Q
Q ta query height

Output:
Prottek query te 2 ta value:
shorter taller

Sample Input:
4
1 4 5 7
4
4 6 8 10

Sample Output:
1 5
5 7
7 X
7 X
*/