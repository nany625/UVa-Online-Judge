#include <stdio.h>
#include <math.h>

int main() {
	int n;
	scanf("%d", &n);
	while(n--) {
		int x, y;
		scanf("%d %d", &x, &y);
		if(x == y)
			puts("0");
		else {
		    int maxLen = sqrt(y - x);
			if(maxLen == sqrt(y - x))
				printf("%d\n", 2 * maxLen - 1);
			else if(maxLen < sqrt(y - x - maxLen))
				printf("%d\n", 2 * maxLen + 1);
			else
				printf("%d\n", 2 * maxLen);
		}
	}
	return 0;
}
