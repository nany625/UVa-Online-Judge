#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *str;
    int sortedness;
} DNA;

int sortedness(char *array) {
    int count = 0, len = strlen(array);
    for(int i = 0; i < len - 1; ++i) {
        for(int j = i + 1; j < len; ++j)
            count += array[i] > array[j];
    }
    return count;
}

int compare(const void *a, const void *b) {
    return ((DNA*)a)->sortedness > ((DNA*)b)->sortedness;
}

int main() {
	int M;
	scanf("%d", &M);
	while(M--) {
	    int m;
	    scanf("%*d %d", &m);
	    DNA dnas[m];
	    for(int i = 0; i < m; ++i) {
	        dnas[i].str = NULL;
            scanf("%ms", &dnas[i].str);
	        dnas[i].sortedness = sortedness(dnas[i].str);
	    }
	    qsort(dnas, m, sizeof(DNA), compare);
	    for(int i = 0; i < m; ++i) {
            printf("%s\n", dnas[i].str);
            free(dnas[i].str);
        }
	    if(M)
	        putchar('\n');
	}
	return 0;
}
