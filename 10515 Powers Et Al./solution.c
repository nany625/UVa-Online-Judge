#include <stdio.h>
#include <string.h>

char lastDigit[][5] = {"6248", "1397", "64", "", "", "1793", "6842", "19"};
int cycle[] = {4, 4, 2, 0, 0, 4, 4, 2};

int main() {
    char m[102], n[102];
    while(scanf("%s %s", m, n) && (m[0] != '0' || n[0] != '0')) {
        int base = m[strlen(m) - 1] - '0';
        if(base == 0)
            puts("0");
        else if(base == 1 || n[0] == '0')
            puts("1");
        else if(base == 5 || base == 6)
            printf("%d\n", base);
        else {
            int len = strlen(n), N;
            if(len == 1)
                N = n[0] - '0';
            else
                N = 10 * (n[len - 2] - '0') + n[len - 1] - '0';
            printf("%c\n", lastDigit[base - 2][N % cycle[base - 2]]);
        }
    }
	return 0;
}
