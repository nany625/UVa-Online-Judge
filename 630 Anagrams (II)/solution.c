#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char word[21], sortedWord[21];
} Anagram;

int compare(const void *a, const void *b) {
    return *(char*)a - *(char*)b;
}

int main() {
	int T;
	scanf("%d", &T);
	bool firstCase = true;
	while(T--) {
	    if(!firstCase)
	        putchar('\n');
	    int N;
	    scanf("%d", &N);
	    Anagram anagrams[N];
	    for(int i = 0; i < N; ++i) {
	        scanf("%s", anagrams[i].word);
	        strcpy(anagrams[i].sortedWord, anagrams[i].word);
	        int len = strlen(anagrams[i].sortedWord);
	        qsort(anagrams[i].sortedWord, len, sizeof(char), compare);
	    }
	    char test[21], sortedTest[21];
	    while(scanf("%s", test) && strcmp(test, "END") != 0) {
	        printf("Anagrams for: %s\n", test);
	        strcpy(sortedTest, test);
	        int len = strlen(sortedTest);
	        qsort(sortedTest, len, sizeof(char), compare);
	        int count = 0;
	        for(int i = 0; i < N; ++i) {
	            if(strcmp(sortedTest, anagrams[i].sortedWord) == 0)
	                printf("  %d) %s\n", ++count, anagrams[i].word);
	        }
	        if(count == 0)
	            printf("No anagrams for: %s\n", test);
	    }
	    firstCase = false;
	}
	return 0;
}
