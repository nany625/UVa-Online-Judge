#include <stdio.h>

int main() {
    int N;
    scanf("%d", &N);
    while(N--) {
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        puts(a + b > c && b + c > a && a + c > b ? "OK" : "Wrong!!");
    }
    return 0;
}
