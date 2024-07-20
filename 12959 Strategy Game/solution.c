#include <stdio.h>

int main() {
	int J, R;
	while(scanf("%d %d", &J, &R) == 2) {
		int points[J];
		for(int i = 0; i < J; ++i)
			points[i] = 0;
		int max = 0, winner, point;
		while(R--) {
			for(int i = 0; i < J; ++i) {
				scanf("%d", &point);
				points[i] += point;
				if(R == 0) {
					if(max <= points[i]) {
						max = points[i];
						winner = i + 1;
					}
				}
			}
		}
		printf("%d\n", winner);
	}
	return 0;
}
