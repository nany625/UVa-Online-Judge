#include <stdio.h>
#include <stdbool.h>

int main() {
	int cases;
	scanf("%d", &cases);
	bool firstCase = true;
	while(cases--) {
		if(!firstCase)
			puts("");
		int amplitude, frequency;
		scanf("%d %d", &amplitude, &frequency);
		bool firstWave = true;
		while(frequency--) {
			if(!firstWave)
				puts("");
			for(int i = 1; i <= amplitude; ++i) {
				for(int j = 1; j <= i; ++j)
					printf("%d", i);
				puts("");
			}
			for(int i = amplitude - 1; i >= 1; --i) {
				for(int j = 1; j <= i; ++j)
					printf("%d", i);
				puts("");
			}
			firstWave = false;
		}
		firstCase = false;
	}
	return 0;
}
