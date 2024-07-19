#include <stdio.h>

int main() {
    int Mondays[] = {3, 0, 0, 4, 2, 6, 4, 1, 5, 3, 0, 5};
	char str[][10] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int cases;
	scanf("%d", &cases);
	while(cases--) {
		int M, D;
		scanf("%d %d", &M, &D);
		printf("%s\n", str[(D + 7 - Mondays[M - 1]) % 7]);
	}
    return 0;
}
