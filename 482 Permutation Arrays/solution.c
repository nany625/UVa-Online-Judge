#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
	
typedef struct {
    int p;
    char number[9];
} Data;

void InsertionSort(Data *array, int size) {
    for(int i = 1; i < size; ++i) {
        int j = i - 1;
        Data temp = array[i];
        while(j >= 0 && temp.p < array[j].p) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = temp;
    }
}

int main() {
	int cases;
	scanf("%d", &cases);
	bool blankLine = false;
	while(cases--) {
	    if(blankLine)
	        puts("");
	    getchar();
	    getchar();
	    char buffer[25];
	    fgets(buffer, sizeof(buffer), stdin);
	    buffer[strcspn(buffer, "\n")] = '\0';
	    Data *datas = NULL;
	    int size = 0;
	    char *token = strtok(buffer, " ");
	    while(token) {
	        datas = (Data*)realloc(datas, (size + 1) * sizeof(Data));
	        datas[size++].p = atoi(token);
	        token = strtok(NULL, " ");
	    }
	    for(int i = 0; i < size; ++i)
	        scanf("%s", datas[i].number);
	    InsertionSort(datas, size);
	    for(int i = 0; i < size; ++i)
	        printf("%s\n", datas[i].number);
	    free(datas);
	    blankLine = true;
	}
	return 0;
}
