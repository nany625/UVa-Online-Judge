#include <stdio.h>
#include <stdlib.h>

int main() {
	int N;
	scanf("%d", &N);
	char part1[5];
	int part2;
	while(N--) {
	    scanf("%4s %d", part1, &part2);
	    puts(abs(26 * 26 * (part1[0] - 'A') +  26 * (part1[1] - 'A') + (part1[2] - 'A') - part2) <= 100 ? "nice" : "not nice");
	}
	return 0;
}
