#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int M[1000][10], Ti[1000];

int GCD(int i, int j) {
	return j == 0 ? i : GCD(j, i % j);
}

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int N;
		scanf("%d", &N);
		int period = 1;
		for(int i = 0; i < N; ++i) {
			scanf("%d", &Ti[i]);
			period = period * Ti[i] / GCD(period, Ti[i]);
			for(int j = 0; j < Ti[i]; ++j)
				scanf("%d", &M[i][j]);
		}
		bool eaten[N];
		memset(eaten, 0, sizeof(eaten));
		int C = 0, D = 0, prev = 0;
		while(C < N && D - prev < period) {
			int min = 251, cowNum, count = 0;
			for(int i = 0; i < N; ++i) {
				if(eaten[i])
					continue;
				if(min > M[i][D % Ti[i]]) {
					min = M[i][D % Ti[i]];
					cowNum = i;
					count = 1;
				} else if(min == M[i][D % Ti[i]])
					++count;
			}
			if(count == 1) {
				eaten[cowNum] = true;
				++C;
				prev = D;
			}
			++D;
		}
		if(C == 0)
			printf("%d 0\n", N);
		else
			printf("%d %d\n", N - C, prev + 1);
	}
	return 0;
}
