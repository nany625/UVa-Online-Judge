#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int a, b;
        scanf("%d %d", &a, &b);
        puts(a < b ? "<" : a > b ? ">" : "=");
    }
    return 0;
}
