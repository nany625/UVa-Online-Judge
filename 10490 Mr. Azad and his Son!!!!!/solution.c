#include <stdio.h>

int table[] = {
    0, 0, 1, 1, 3, 1, 3, 1, 3, 3, 
    3, 2, 3, 1, 3, 3, 3, 1, 3, 1, 
    3, 3, 3, 2, 3, 3, 3, 3, 3, 2, 
    3, 1
};

int main() {
    int n;
    while(scanf("%d", &n) && n != 0) {
        switch(table[n]) {
            case 1:
                printf("Perfect: %ld!\n", ((long)1 << n - 1) * ((1 << n) - 1));
                break;
            case 2:
                puts("Given number is prime. But, NO perfect number is available.");
                break;
            case 3:
                puts("Given number is NOT prime! NO perfect number is available.");
        }
    }
    return 0;
}
