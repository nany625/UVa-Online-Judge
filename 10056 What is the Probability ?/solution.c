#include <stdio.h>
#include <math.h>

int main() {
	int S;
	scanf("%d", &S);
	while(S--) {
		int N, I;
		double p;
		scanf("%d %lf %d", &N, &p, &I);
		printf("%.4lf\n", p > 0 ? p * pow(1 - p, I - 1) / (1 - pow(1 - p, N)) : p);
	}
	return 0;
}
