#include <stdio.h>

int main() {
    int K;
	while(scanf("%d", &K) && K != 0) {
	    short N, M;
	    scanf("%hd %hd", &N, &M);
	    while(K--) {
	        short X, Y;
	        scanf("%hd %hd", &X, &Y);
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
