#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	
typedef struct {
    int p;
    char *number;
} Data;

int compare(const void *a, const void *b) {
    return ((Data*)a)->p > ((Data*)b)->p;
}

int main() {
	int cases;
	scanf("%d", &cases);
    char *buffer = NULL;
	size_t bufsize = 0;
	while(cases--) {
	    getchar();
	    getchar();
	    getline(&buffer, &bufsize, stdin);
	    Data *datas = NULL;
	    int size = 0;
	    char *token = strtok(buffer, " ");
	    while(token) {
	        datas = (Data*)realloc(datas, (size + 1) * sizeof(Data));
	        datas[size++].p = atoi(token);
	        token = strtok(NULL, " ");
	    }
	    for(int i = 0; i < size; ++i)
	        scanf("%ms", &datas[i].number);
	    qsort(datas, size, sizeof(Data), compare);
	    for(int i = 0; i < size; ++i) {
	        puts(datas[i].number);
	        free(datas[i].number);
	    }
	    free(datas);
	    if(cases)
	        putchar('\n');
	}
    free(buffer);
	return 0;
}
