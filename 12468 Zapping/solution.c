#include <stdio.h>

int main() {
    int a, b;
    while(scanf("%d %d", &a, &b) && a != -1) {
        if(a > b) {
            int temp = a;
            a = b;
            b = temp;
        }
        printf("%d\n", b - a < a + 100 - b ? b - a : a + 100 - b);
    }
	return 0;
}
