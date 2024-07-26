#include <stdio.h>
#include <string.h>

int lastDigit[] = {
    0, 1, 5, 2, 8, 3, 9, 2, 8, 7, 
    7, 8, 4, 7, 3, 8, 4, 1, 5, 4,
};

int main() {
    char N[102];
    while(scanf("%s", N) && N[0] != '0') {
        int dividend = 0, len = strlen(N);
        for(int i = 0; i < len - 1; ++i)
            dividend = (10 * dividend + N[i] - '0') % 20;
        dividend = 10 * dividend + N[len - 1] - '0';
        printf("%d\n", (dividend / 20 * 4 + lastDigit[dividend % 20]) % 10);
    }
	return 0;
}
