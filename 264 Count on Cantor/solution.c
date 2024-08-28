#include <stdio.h>
#include <math.h>

int main() {
    int number;
    while(scanf("%d", &number) == 1) {
        int i = ceil((-1 + sqrt(1 + (number << 3))) / 2);
        int a = i + 1 - number + ((i - 1) * i >> 1);
        int b = number - ((i - 1) * i >> 1);
        if(i & 1)
            printf("TERM %d IS %d/%d\n", number, a, b);
        else
            printf("TERM %d IS %d/%d\n", number, b, a);
    }
    return 0;
}
