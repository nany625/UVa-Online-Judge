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
			else if(X > N && Y > M)
				puts("NE");
			else if(X < N && Y > M)
				puts("NO");
			else if(X < N && Y < M)
				puts("SO");
			else
				puts("SE");
	    }
	}
    return 0;
}
