#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char alpha, count = 0;
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
	for(int i = 0; i < 26; ++i)
	    frequencies[i].alpha = 'A' + i;
	int n;
	scanf("%d", &n);
	getchar();
	while(n--) {
        char *text = NULL;
	    size_t textsize = 0;
	    getline(&text, &textsize, stdin);
	    int len = strlen(text);
	    for(int i = 0; i < len; ++i) {
	        if(isupper(text[i]))
	            ++frequencies[text[i] - 'A'].count;
	        else if(islower(text[i]))
	            ++frequencies[text[i] - 'a'].count;
	    }
        free(text);
	}
	qsort(frequencies, 26, sizeof(Frequency), compare);
	for(int i = 0; i < 26 && frequencies[i].count > 0; ++i)
	    printf("%c %d\n", frequencies[i].alpha, frequencies[i].count);
	return 0;
}
