#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
	    int N, P;
	    scanf("%d %d", &N, &P);
	    int h[P];
	    for(int i = 0; i < P; ++i)
	        scanf("%d", &h[i]);
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
