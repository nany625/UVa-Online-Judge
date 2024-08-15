#include <stdio.h>

int main() {
	int cases;
	scanf("%d", &cases);
	while(cases--) {
	    int n;
	    scanf("%d", &n);
	    puts(n % 3 == 1 ? "NO" : "YES");
	}
	return 0;
}
