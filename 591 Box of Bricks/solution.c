#include <stdio.h>

int main() {
	int set = 0, n;
	while(scanf("%d", &n) && n != 0) {
		int h[n], total = 0;
		for(int i = 0; i < n; ++i) {
			scanf("%d", &h[i]);
			total += h[i];
		}
		total /= n;
		int moves = 0;
		for(int i = 0; i < n; ++i) {
			if(h[i] > total)
				moves += h[i] - total;
		}	
		printf("Set #%d\nThe minimum number of moves is %d.\n\n", ++set, moves);
	}
	return 0;
}
