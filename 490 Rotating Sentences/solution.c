#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
	char **sentences = NULL, sentence[102];
	int maxLen = 0, size = 0;
	while(fgets(sentence, sizeof(sentence), stdin)) {
		sentence[strcspn(sentence, "\n")] = '\0';
		maxLen = maxLen > strlen(sentence) ? maxLen : strlen(sentence);
		sentences = (char**)realloc(sentences, (size + 1) * sizeof(char*));
		sentences[size++] = strdup(sentence);
	}
	for(int i = 0; i < maxLen; ++i) {
	    for(int j = size - 1; j >= 0; --j)
	        putchar(i < strlen(sentences[j]) ? sentences[j][i] : ' ');
	    putchar('\n');
	}
	for(int i = 0; i < size; ++i)
	    free(sentences[i]);
	free(sentences);
	return 0;
}
