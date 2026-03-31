#include <stdio.h>
#include <string.h>

int main() {
    int n;
    char s[105];

    scanf("%d", &n);
    scanf("%s", s);

    int count8 = 0;

    // koyta '8' ase count kortesi
    for(int i = 0; i < n; i++) {
        if(s[i] == '8')
            count8++;
    }

    // ekta phone number banate 11 ta digit lage
    int total_possible = n / 11;

    // kintu prottek number er start e '8' lagbe
    // tai min(count8, total_possible)
    int result = count8 < total_possible ? count8 : total_possible;

    printf("%d\n", result);

    return 0;
}

/*
Problem: Phone Number from Cards

Description:
Ekta phone number valid hobe jodi:
1) length = 11
2) first digit = '8'
3) baki 10 ta digit je kono hote pare

Tomar kase n ta digit card ase.
Prottek card ekbar use kora jabe.

Tomake ber korte hobe maximum koyta phone number banaite parba.

Important logic:
- Prottek number e 11 ta digit lagbe
- Prottek number er jonno 1 ta '8' must

Tai answer = min( total '8', n/11 )

Input:
n
string of n digits

Output:
maximum phone number count

Sample Input:
11
00000000008

Sample Output:
1

Sample Input:
22
0011223344556677889988

Sample Output:
2

Sample Input:
11
31415926535

Sample Output:
0

Explanation:
Case 1:
1 ta '8' ase → 1 ta number possible

Case 2:
2 ta '8' ase → 2 ta number possible

Case 3:
kon '8' nai → 0
*/