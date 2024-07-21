#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char alpha, count;
} Frequency;

int compare(const void *a, const void *b) {
    Frequency *f1 = (Frequency*)a;
    Frequency *f2 = (Frequency*)b;
    if(f1->count != f2->count)
        return f2->count - f1->count;
    return f1->alpha - f2->alpha;
}

int main() {
	Frequency frequencies[26];
	for(int i = 0; i < 26; ++i) {
	    frequencies[i].alpha = 'A' + i;
	    frequencies[i].count = 0;
	}
	int n;
	scanf("%d", &n);
	getchar();
    char *buffer = NULL;
	size_t bufsize = 0;
	while(n--) {
	    getline(&buffer, &bufsize, stdin);
	    int len = strlen(buffer);
	    for(int i = 0; i < len; ++i) {
	        if(isupper(buffer[i]))
	            ++frequencies[buffer[i] - 'A'].count;
	        else if(islower(buffer[i]))
	            ++frequencies[buffer[i] - 'a'].count;
	    }
	}
	qsort(frequencies, 26, sizeof(Frequency), compare);
	for(int i = 0; i < 26 && frequencies[i].count > 0; ++i)
	    printf("%c %d\n", frequencies[i].alpha, frequencies[i].count);
	free(buffer);
    return 0;
}
