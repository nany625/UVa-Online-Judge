#include <stdio.h>

int bigMod(long B, int P, int M) {
    if(P == 0)
        return 1 % M;
    if(P == 1)
        return B % M;
    int temp = bigMod(B, P / 2, M);
    if(P % 2 == 0)
        return temp * temp % M;
    return temp * temp * B % M;
}

int main() {
    long B;
    int P, M;
    while(scanf("%ld %d %d", &B, &P, &M) == 3)
        printf("%d\n", bigMod(B, P, M));
	return 0;
}
