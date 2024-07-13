#include <stdio.h>

int main() {
    int pos, num1, num2, num3;
    while(scanf("%d %d %d %d", &pos, &num1, &num2, &num3) && (pos != 0 || num1 != 0 || num2 != 0 || num3 != 0)) {
        int degree = 1080 + 9 * ((pos - num1 + 40) % 40 + (num2 - num1 + 40) % 40 + (num2 - num3 + 40) % 40);
        printf("%d\n", degree);
    }
    return 0;
}
