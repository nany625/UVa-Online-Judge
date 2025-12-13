#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int N, B;
        scanf("%d %d", &N, &B);
        int chocolate = 0;
        while(B--) {
            int K;
            scanf("%d", &K);
            int temp = 1;
            while(K--) {
                int a;
                scanf("%d", &a);
                temp = temp * a % N;
            }
            chocolate += temp;
        }
        printf("%d\n", chocolate % N);
    }
	return 0;
}
