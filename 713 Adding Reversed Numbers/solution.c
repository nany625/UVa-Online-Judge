#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    char num1[201], num2[201], sum[202];
    while(N--) {
        scanf("%s %s", num1, num2);
        int len1 = strlen(num1), len2 = strlen(num2), carry = 0;
        while(num1[len1 - 1] == '0')
            --len1;
        while(num2[len2 - 1] == '0')
            --len2;
        if(len1 > len2) {
            memset(num2 + len2, '0', len1 - len2);
            for(int i = 0; i < len1; ++i) {
                sum[i] = num1[i] + num2[i] - ('0' << 1) + carry;
                carry = sum[i] / 10;
                sum[i] = sum[i] % 10 + '0';
            }
            int i = 0;
            while(sum[i] == '0')
                ++i;
            while(i < len1)
                putchar(sum[i++]);
        } else {
            memset(num1 + len1, '0', len2 - len1);
            for(int i = 0; i < len2; ++i) {
                sum[i] = num1[i] + num2[i] - ('0' << 1) + carry;
                carry = sum[i] / 10;
                sum[i] = sum[i] % 10 + '0';
            }
            int i = 0;
            while(sum[i] == '0')
                ++i;
            while(i < len2)
                putchar(sum[i++]);
        }
        if(carry == 1)
            putchar('1');
        putchar('\n');
    }
	return 0;
}
