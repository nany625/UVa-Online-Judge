#include <stdio.h>
#include <math.h>

int main() {
    int n;
    while(scanf("%d", &n) == 1) {
        double temp = log2(n);
        printf("%d\n", (int)temp + n - 2 + (temp != (int)temp));
    }
	return 0;
}
