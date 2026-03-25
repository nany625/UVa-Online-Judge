#include <stdio.h>
#include <math.h>

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		int n;
		scanf("%d", &n);
		long limit = sqrt(n), res = 0;
		int quotients[limit + 1];
		for(int i = 1; i <= limit; ++i) {
			quotients[i] = n / i;
			res += quotients[i];
		}
		for(int i = 1; i < limit; ++i)
			res += i * (quotients[i] - quotients[i + 1]);
		if(limit != quotients[limit])
			res += limit * (quotients[limit] - (n / (limit + 1)));
		printf("%ld\n", res);
	}
	return 0;
}
