#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		int senior, junior;
		scanf("%d %d", &senior, &junior);
		int maxScore = senior > junior ? senior : junior, maxDist = senior - junior;
		while(n-- > 2) {
			scanf("%d", &junior);
			if(maxDist < maxScore - junior)
			    maxDist = maxScore - junior;
			if(maxScore < junior)
			    maxScore = junior;
		}
		printf("%d\n", maxDist);
	}
	return 0;
}
