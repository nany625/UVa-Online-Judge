#include <stdio.h>

short costs[36];

int main() {
	int cases;
	scanf("%d", &cases);
	for(int i = 1; i <= cases; ++i) {
		if(i > 1)
			putchar('\n');
		printf("Case %d:\n", i);
		for(int j = 0; j < 36; ++j)
			scanf("%hd", &costs[j]);
		int queries;
		scanf("%d", &queries);
		while(queries--) {
			int number;
			scanf("%d", &number);
			printf("Cheapest base(s) for number %d:", number);
			short totalCosts[35] = {}, cheapest = 0;
			for(int base = 2; base <= 36; ++base) {
				int temp = number;
				do {
					totalCosts[base - 2] += costs[temp % base];
					temp /= base;
				} while(temp > 0);
				if(cheapest > totalCosts[base - 2] || cheapest == 0)
					cheapest = totalCosts[base - 2];
			}
			for(int base = 2; base <= 36; ++base) {
				if(totalCosts[base - 2] == cheapest)
					printf(" %d", base);
			}
			putchar('\n');
		}
	}
	return 0;
}
