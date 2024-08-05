#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
	int cases;
	scanf("%d", &cases);
	getchar();
	getchar();
    char plaintext[66], substitution[66], text[66];
	bool firstCase = true;
	while(cases--) {
	    if(!firstCase)
	        putchar('\n');
	    fgets(plaintext, sizeof(plaintext), stdin);
		fgets(substitution, sizeof(substitution), stdin);
		printf("%s%s", substitution, plaintext);
		int len = strlen(plaintext);
		char ASCII[128];
		memset(ASCII, '\0', 128);
		for(int i = 0; i < len; ++i)
		    ASCII[(int)plaintext[i]] = substitution[i];
		while(fgets(text, sizeof(text), stdin) && strcmp(text, "\n") != 0) {
		    len = strlen(text);
		    for(int i = 0; i < len; ++i)
		        putchar(ASCII[(int)text[i]] != '\0' ? ASCII[(int)text[i]] : text[i]);
		}
		firstCase = false;
	}
	return 0;
}
