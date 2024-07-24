#include <stdio.h>

int main() {
    int K;
	while(scanf("%d", &K) && K != 0) {
	    int N, M;
	    scanf("%d %d", &N, &M);
	    while(K--) {
	        int X, Y;
	        scanf("%d %d", &X, &Y);
			if(X == N || Y == M)
				puts("divisa");
			else {
			    putchar(Y > M ? 'N' : 'S');
			    putchar(X > N ? 'E' : 'O');
			    putchar('\n');
			}
	    }
	}
    return 0;
}
