#include <stdio.h>

int cp[] = {
    113, 131, 197, 199, 311, 337, 373, 719, 733, 919, 
    971, 991, 1193, 1931, 3119, 3779, 7793, 7937, 9311, 9377, 
    11939, 19391, 19937, 37199, 39119, 71993, 91193, 93719, 93911, 99371, 
    193939, 199933, 319993, 331999, 391939, 393919, 919393, 933199, 939193, 939391, 
    993319, 999331
};

int binarySearch(int key) {
    int left = 0, right = 41;
	while(left <= right) {
		int mid = left + ((right - left) >> 1);
		if(cp[mid] == key)
			return mid;
		if(cp[mid] < key)
			left = mid + 1;
		else
			right = mid - 1;
	}
	return left;
}

int main() {
	int i;
	while(scanf("%d", &i) && i != -1) {
		int j;
		scanf("%d", &j);
		int posI = binarySearch(i), posJ = binarySearch(j);
		int cpCount = (posJ - posI) + (posJ < 42 && cp[posJ] == j);
		if(cpCount == 0)
		    puts("No Circular Primes.");
		else
			printf("%d Circular Prime%s.\n", cpCount, cpCount > 1 ? "s" : "");
	}
	return 0;
}
