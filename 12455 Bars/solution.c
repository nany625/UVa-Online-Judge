#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isSubsetSum(short *array, int size, int sum) {
	bool subsetSum[sum + 1];
	subsetSum[0] = true;
	memset(subsetSum + 1, 0, sum * sizeof(bool));
	for(int i = 0; i < size && !subsetSum[sum]; ++i) {
	    for(int j = sum; j >= array[i] && !subsetSum[sum]; --j)
	        subsetSum[j] |= subsetSum[j - array[i]];
	}
	return subsetSum[sum];
}

int main() {
    int t;
	scanf("%d", &t);
	while(t--) {
		int n, p;
		scanf("%d %d", &n, &p);
		short barsLen[p];
		for(int i = 0; i < p; ++i)
			scanf("%hd", &barsLen[i]);
		puts(isSubsetSum(barsLen, p, n) ? "YES" : "NO");
	}
	return 0;
}
