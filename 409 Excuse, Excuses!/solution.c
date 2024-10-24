#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    char excuse[72], count;
} Excuse;

bool allLowerCase(char *array) {
    int len = strlen(array);
    for(int i = 0; i < len; ++i) {
        if(!islower(array[i]))
            return false;
    }
    return true;
}

int compare(const void *a, const void *b) {
    return strcmp(*(const char**)a, *(const char**)b);
}

bool binarySearch(char **array, int size, char *key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left >> 1);
        int cmp = strcasecmp(array[mid], key);
        if(cmp == 0)
            return true;
        if(cmp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return false;
}

int main() {
	int set = 0, K, E;
	while(scanf("%d %d", &K, &E) == 2) {
	    printf("Excuse Set #%d\n", ++set);
	    char **keywords = NULL, keyword[21];
	    int size = 0;
	    while(K--) {
	        scanf("%s", keyword);
	        if(allLowerCase(keyword)) {
	            keywords = (char**)realloc(keywords, (size + 1) * sizeof(char*));
	            keywords[size++] = strdup(keyword);
	        }
	    }
	    qsort(keywords, size, sizeof(char*), compare);
	    getchar();
	    Excuse excuses[E];
	    char max = 0;
	    for(int i = 0; i < E; ++i) {
	        fgets(excuses[i].excuse, sizeof(excuses[i].excuse), stdin);
	        excuses[i].count = 0;
	        int start = 0, len = strlen(excuses[i].excuse);
	        while(start < len) {
	            if(isalpha(excuses[i].excuse[start])) {
	                int end = start + 1;
	                while(isalpha(excuses[i].excuse[end]))
	                    ++end;
	                char *token = strndup(excuses[i].excuse + start, end - start);
	                excuses[i].count += binarySearch(keywords, size, token);
	                free(token);
	                start = end;
	            }
	            ++start;
	        }
	        max = max > excuses[i].count ? max : excuses[i].count;
	    }
	    for(int i = 0; i < E; ++i) {
	        if(excuses[i].count == max)
	            fputs(excuses[i].excuse, stdout);
	    }
	    putchar('\n');
	}
	return 0;
}
