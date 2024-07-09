#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int T;
	scanf("%d", &T);
	while(T--) {
		char *s = NULL;
		scanf("%ms", &s);
		int score = 0, temp = 0, i = 0, len = strlen(s);
        do {
            if(s[i] == 'O')
                score += ++temp;
            else
                temp = 0;
        } while(++i < len);
		printf("%d\n", score);
		free(s);
	}
	return 0;
}
