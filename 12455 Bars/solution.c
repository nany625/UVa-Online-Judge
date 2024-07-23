#include <stdio.h>
#include <stdbool.h>

bool isSubsetSum(short *array, int size, int sum) {
	bool subsetSum[sum + 1];
	subsetSum[0] = true;
	for(int i = 1; i <= sum; ++i)
	    subsetSum[i] = false;
	for(int i = 0; i < size && !subsetSum[sum]; ++i) {
	    for(int j = sum; j >= array[i] && !subsetSum[sum]; --j) {
	        if(subsetSum[j - array[i]])
	            subsetSum[j] = true;
	    }
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
		printf("%s\n", isSubsetSum(barsLen, p, n) ? "YES" : "NO");
	}
	return 0;
}
