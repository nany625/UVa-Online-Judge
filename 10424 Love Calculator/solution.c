#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int sum(char *array) {
    int result = 0, len = strlen(array);
    for(int i = 0; i < len; ++i) {
        if(isupper(array[i]))
            result += array[i] - 'A' + 1;
        else if(islower(array[i]))
            result += array[i] - 'a' + 1;
    }
    return result;
}

int sumOfDigits(int n) {
    int result = 0;
    while(n > 0) {
        result += n % 10;
        n /= 10;
    }
    return result > 9 ?  sumOfDigits(result) : result;
}

int main() {
    char *name1 = NULL, *name2 = NULL;
    size_t bufname1 = 0, bufname2 = 0;
    while(getline(&name1, &bufname1, stdin) != -1 && getline(&name2, &bufname2, stdin)) {
        name1[strcspn(name1, "\n")] = '\0';
        name2[strcspn(name2, "\n")] = '\0';
        int sum1 = sum(name1), sum2 = sum(name2);
        int sumOfDigits1 = sumOfDigits(sum1), sumOfDigits2 = sumOfDigits(sum2);
        if(sumOfDigits1 > sumOfDigits2) {
            int temp = sumOfDigits1;
            sumOfDigits1 = sumOfDigits2;
            sumOfDigits2 = temp;
        }
        printf("%.2f %%\n", 100.0 * sumOfDigits1 / sumOfDigits2);
    }
    return 0;
}
