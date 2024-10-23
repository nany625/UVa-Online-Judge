#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	char *country, count;
} Conquest;

int binarySearch(Conquest *array, int size, char *key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left >> 1);
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
	getchar();
	char buffer[77];
	Conquest *conquests = NULL;
	int size = 0;
	while(n--) {
	    fgets(buffer, sizeof(buffer), stdin);
	    char *token = strtok(buffer, " ");
		int pos = binarySearch(conquests, size, token);
		if(pos < size && strcmp(conquests[pos].country, token) == 0)
		    ++conquests[pos].count;
		else {
		    conquests = (Conquest*)realloc(conquests, (size + 1) * sizeof(Conquest));
		    for(int i = size++; i > pos; --i)
		        conquests[i] = conquests[i - 1];
		    conquests[pos].country = strdup(token);
            conquests[pos].count = 1;
		}
	}
	for(int i = 0; i < size; ++i) {
	    printf("%s %d\n", conquests[i].country, conquests[i].count);
	    free(conquests[i].country);
	}
	free(conquests);
	return 0;
}
