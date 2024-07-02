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

void InsertionSort(char **array, int size) {
    for(int i = 1; i < size; ++i) {
        int j = i - 1;
        char *temp = array[i];
        while(j >= 0 && strcmp(temp, array[j]) < 0) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = temp;
    }
}

bool binarySearch(char **array, int size, char *key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
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
	            keywords[size] = (char*)malloc((strlen(keyword) + 1) * sizeof(char));
	            strcpy(keywords[size++], keyword);
	        }
	    }
	    InsertionSort(keywords, size);
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
	                char token[end - start + 1];
	                strncpy(token, excuses[i].excuse + start, end - start);
	                token[end - start] = '\0';
	                if(binarySearch(keywords, size, token))
	                    ++excuses[i].count;
	                start = end;
	            }
	            ++start;
	        }
	        max = max > excuses[i].count ? max : excuses[i].count;
	    }
	    for(int i = 0; i < E; ++i) {
	        if(excuses[i].count == max)
	            printf("%s", excuses[i].excuse);
	    }
	    puts("");
	    for(int i = 0; i < size; ++i)
	        free(keywords[i]);
	    free(keywords);
	}
	return 0;
}
