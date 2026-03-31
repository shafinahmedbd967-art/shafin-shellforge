#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T); // total test case

    for(int i = 1; i <= T; i++) {
        int n;
        scanf("%d", &n);

        int original = n;
        int reversed = 0;

        // number reverse kortesi
        while(n > 0) {
            int digit = n % 10;
            reversed = reversed * 10 + digit;
            n /= 10;
        }

        // check palindrome kina
        if(original == reversed) {
            printf("Case %d: Yes\n", i);
        } else {
            printf("Case %d: No\n", i);
        }
    }

    return 0;
}

/*
Problem: Palindromic Number Check

Description:
Ekta number ke palindromic bola hoy jodi oi number ta reverse korleo same thake.
Example: 121, 1331, 16161

Tomake T ta test case deya hobe.
Prottek test case e ekta integer n thakbe.
Check korte hobe n palindrome kina.

Jodi hoy → Yes
Na hole → No

Output format:
Case 1: Yes/No
Case 2: Yes/No
...

Input:
Prothome T (test case number)
Tarpor T ta line e n

Constraints:
1 ≤ T ≤ 20000
0 ≤ n < 1000000000

Sample Input:
5
1
21
16161
523125
0

Sample Output:
Case 1: Yes
Case 2: No
Case 3: Yes
Case 4: No
Case 5: Yes

Explanation:
1 → same reverse → Yes
21 → reverse 12 → No
16161 → same → Yes
523125 → reverse alada → No
0 → same → Yes
*/