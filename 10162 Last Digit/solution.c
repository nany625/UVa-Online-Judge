// #解法一
#include <stdio.h>
#include <string.h>

int lastDigit[] = {
    0, 1, 5, 2, 8, 3, 9, 2, 8, 7, 
    7, 8, 4, 7, 3, 8, 4, 1, 5, 4
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

// #解法二
#include <stdio.h>
#include <string.h>

char lastDigit[] = {
    '0', '1', '5', '2', '8', '3', '9', '2', '8', '7',
    '7', '8', '4', '7', '3', '8', '4', '1', '5', '4',
    '4', '5', '9', '6', '2', '7', '3', '6', '2', '1',
    '1', '2', '8', '1', '7', '2', '8', '5', '9', '8',
    '8', '9', '3', '0', '6', '1', '7', '0', '6', '5',
    '5', '6', '2', '5', '1', '6', '2', '9', '3', '2',
    '2', '3', '7', '4', '0', '5', '1', '4', '0', '9',
    '9', '0', '6', '9', '5', '0', '6', '3', '7', '6',
    '6', '7', '1', '8', '4', '9', '5', '8', '4', '3',
    '3', '4', '0', '3', '9', '4', '0', '7', '1', '0'
};

int main() {
    char N[102];
    while(scanf("%s", N) && N[0] != '0') {
        int len = strlen(N);
        if(len == 1)
            printf("%c\n", lastDigit[N[0] - '0']);
        else
            printf("%c\n", lastDigit[(N[len - 2] - '0') * 10 + N[len - 1] - '0']);
    }
	return 0;
}
