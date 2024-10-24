#include <stdio.h>

int main() {
	int cases;
	scanf("%d", &cases);
	while(cases--) {
		int amplitude, frequency;
		scanf("%d %d", &amplitude, &frequency);
		while(frequency--) {
			for(int i = 1; i <= amplitude; ++i) {
				for(int j = 1; j <= i; ++j)
					putchar(i + '0');
				putchar('\n');
			}
			for(int i = amplitude - 1; i >= 1; --i) {
				for(int j = 1; j <= i; ++j)
					putchar(i + '0');
				putchar('\n');
			}
			if(frequency)
				putchar('\n');
		}
		if(cases)
			putchar('\n');
	}
	return 0;
}
