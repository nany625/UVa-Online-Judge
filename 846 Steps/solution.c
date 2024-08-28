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
				printf("%d\n", (maxLen << 1) - 1);
			else if(maxLen < sqrt(y - x - maxLen))
				printf("%d\n", (maxLen << 1) + 1);
			else
				printf("%d\n", maxLen << 1);
		}
	}
	return 0;
}
