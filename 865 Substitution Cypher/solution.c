#include <stdio.h>
#include <string.h>

int main() {
	int cases;
	scanf("%d ", &cases);
    char ASCII[128], plaintext[66], substitution[66], text[66];
	while(cases--) {
	    fgets(plaintext, sizeof(plaintext), stdin);
		fgets(substitution, sizeof(substitution), stdin);
		printf("%s%s", substitution, plaintext);
		memset(ASCII, '\0', sizeof(ASCII));
		int len = strlen(plaintext);
		for(int i = 0; i < len; ++i)
		    ASCII[(int)plaintext[i]] = substitution[i];
		while(fgets(text, sizeof(text), stdin) && strcmp(text, "\n") != 0) {
		    len = strlen(text);
		    for(int i = 0; i < len; ++i)
		        putchar(ASCII[(int)text[i]] != '\0' ? ASCII[(int)text[i]] : text[i]);
		}
	    if(cases)
	        putchar('\n');
	}
	return 0;
}
