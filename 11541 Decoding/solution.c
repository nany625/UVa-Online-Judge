#include <stdio.h>
#include <ctype.h>

int main() {
	int T;
	scanf("%d", &T);
	getchar();
	for(int i = 1; i <= T; ++i) {
		printf("Case %d: ", i);
		char alpha;
		while(isupper((alpha = getchar()))) {
			int frequency;
			scanf("%d", &frequency);
			while(frequency--)
				putchar(alpha);
		}
		puts("");
	}
	return 0;
}
