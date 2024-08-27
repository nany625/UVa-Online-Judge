#include <stdio.h>
#include <math.h>

int main() {
	int N;
	while(scanf("%d", &N) && N != 0) {
		int circle = ceil(sqrt(N)), corner = 1 + circle * (circle - 1);
		if(circle & 1) {
			if(N < corner)
				printf("%d %d\n", circle, circle - (corner - N));
			else
				printf("%d %d\n", circle - (N - corner), circle);
		} else {
			if(N < corner)
				printf("%d %d\n", circle - (corner - N), circle);
			else
				printf("%d %d\n", circle, circle - (N - corner));
		}
	}
	return 0;
}
