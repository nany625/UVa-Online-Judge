#include <stdio.h>
#include <string.h>

int main() {
    int G;
    while(scanf("%d", &G) && G != 0) {
        char str[101];
		scanf("%s", str);
		int len = strlen(str);
		for(int i = 0; i < G; ++i) {
			for(int j = (i + 1) * len / G - 1; j >= i * len / G; --j)
				putchar(str[j]);
		}
		puts("");
    }
    return 0;
}
