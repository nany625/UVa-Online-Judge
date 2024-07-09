#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *country;
	char count;
} Conquest;

int binarySearch(Conquest *array, int size, char *key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(array[mid].country, key);
        if(cmp == 0)
            return mid;
        if(cmp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int main() {
	int n;
	scanf("%d", &n);
	Conquest *conquests = NULL;
	int size = 0;
	while(n--) {
		char *buffer = NULL;
		scanf("%ms", &buffer);
		int pos = binarySearch(conquests, size, buffer);
		if(pos < size && strcmp(conquests[pos].country, buffer) == 0)
		    ++conquests[pos].count;
		else {
		    conquests = (Conquest*)realloc(conquests, (size + 1) * sizeof(Conquest));
		    for(int i = size++; i > pos; --i)
		        conquests[i] = conquests[i - 1];
		    conquests[pos].country = strdup(buffer);
            conquests[pos].count = 1;
		}
		size_t bufsize = 0;
		getline(&buffer, &bufsize, stdin);
		free(buffer);
	}
	for(int i = 0; i < size; ++i) {
	    printf("%s %d\n", conquests[i].country, conquests[i].count);
	    free(conquests[i].country);
	}
	free(conquests);
	return 0;
}
