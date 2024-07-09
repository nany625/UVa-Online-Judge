#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char value;
    short count;
} Frequency;

int contain(Frequency *array, int size, char key) {
    for(int i = 0; i < size; ++i) {
        if(array[i].value == key)
            return i;
    }
    return -1;
}

int compare(const void *a, const void *b) {
    Frequency *f1 = (Frequency*)a;
    Frequency *f2 = (Frequency*)b;
    if(f1->count != f2->count)
        return f1->count - f2->count;
    return f2->value - f1->value;
}

int main() {
	char text[1002];
	bool firstCase = true;
	while(fgets(text, sizeof(text), stdin)) {
	    if(!firstCase)
	        puts("");
	    text[strcspn(text, "\n")] = '\0';
	    Frequency *frequencies = NULL;
	    int size = 0, len = strlen(text);
	    for(int i = 0; i < len; ++i) {
	        int pos = contain(frequencies, size, text[i]);
	        if(pos == -1) {
	            frequencies = (Frequency*)realloc(frequencies, (size + 1) * sizeof(Frequency));
	            frequencies[size].value = text[i];
	            frequencies[size++].count = 1;
	        } else
	            ++frequencies[pos].count;
	    }
	    qsort(frequencies, size, sizeof(Frequency), compare);
	    for(int i = 0; i < size; ++i)
	        printf("%d %hd\n", frequencies[i].value, frequencies[i].count);
	    free(frequencies);
	    firstCase = false;
	}
	return 0;
}
