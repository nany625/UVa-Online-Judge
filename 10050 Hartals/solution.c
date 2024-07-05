#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
	    short N;
	    int P;
	    scanf("%hd %d", &N, &P);
	    short h[P];
	    for(int i = 0; i < P; ++i)
	        scanf("%hd", &h[i]);
	    int hartals = 0;
	    do {
	        if((N - 6) % 7 != 0 && N % 7 != 0) {
	            for(int i = 0; i < P; ++i) {
	                if(N % h[i] == 0) {
	                    ++hartals;
	                    break;
	                }
	            }
	        }
	    } while(N--);
	    printf("%d\n", hartals);
	}
	return 0;
}
