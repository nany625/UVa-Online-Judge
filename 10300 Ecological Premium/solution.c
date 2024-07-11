#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        int f;
        scanf("%d", &f);
        long sum = 0;
        while(f--) {
            long size, friendliness;
            scanf("%ld %*d %ld", &size, &friendliness);
            sum += size * friendliness;
        }
        printf("%ld\n", sum);
    }
	return 0;
}
