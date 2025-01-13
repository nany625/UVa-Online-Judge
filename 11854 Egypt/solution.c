#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int a, b, c;
    while(scanf("%d %d %d", &a, &b, &c) && a != 0) {
        if(a > b)
            swap(&a, &b);
        if(b > c)
            swap(&b, &c);
        puts(a * a + b * b == c * c ? "right" : "wrong");
    }
	return 0;
}
