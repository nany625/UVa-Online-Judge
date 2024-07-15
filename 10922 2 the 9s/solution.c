#include <stdio.h>
#include <string.h>

int sumOfDigits(char *array) {
    int result = 0, len = strlen(array);
    for(int i = 0; i < len; ++i)
        result += array[i] - '0';
    return result;
}

int main() {
    char N[1001];
    while(scanf("%s", N) && strcmp(N, "0") != 0) {
        printf("%s is ", N);
        int degree = 0, temp;
        while((temp = sumOfDigits(N)) > 9 && temp % 9 == 0) {
            ++degree;
            sprintf(N, "%d", temp);
        }
        degree += temp == 9;
        if(degree == 0)
            puts("not a multiple of 9.");
        else
            printf("a multiple of 9 and has 9-degree %d.\n", degree);
    }
    return 0;
}
