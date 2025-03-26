#include <stdio.h>
#include <math.h>

typedef struct {
	int volume, temperature;
} Jar;

int main() {
	int cases;
	scanf("%d", &cases);
	while(cases--) {
		int capacity, temperature, n;
		scanf("%d %d %d", &capacity, &temperature, &n);
		Jar jars[n];
		for(int i = 0; i < n; ++i) {
			scanf("%d %d", &jars[i].volume, &jars[i].temperature);
			jars[i].temperature *= jars[i].volume;
		}
		int start = -1, end = -1;
		double diff = 5.1;
		for(int i = 0; i < n; ++i) {
			int totalVolume = 0;
			double totalTemperature = 0;
			for(int j = i; j < n; ++j) {
				totalVolume += jars[j].volume;
				if(totalVolume > capacity)
					break;
				totalTemperature += jars[j].temperature;
				if(totalVolume << 1 >= capacity) {
					double mixTemperature = totalTemperature / totalVolume;
					if(diff > fabs(mixTemperature - temperature)) {
						start = i;
						end = j;
						diff = fabs(mixTemperature - temperature);
					}
				}
			}
		}
		if(diff > 5)
			puts("Not possible");
		else
			printf("%d %d\n", start, end);
	}
	return 0;
}
