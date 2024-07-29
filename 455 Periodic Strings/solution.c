#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
	int N;
	scanf("%d", &N);
	char s[81];
	bool firstCase = true;
	while(N--) {
		if(!firstCase)
			putchar('\n');
		scanf("%s", s);
		int len = strlen(s), i = 1, length = 0;
        short LPS[len];
		LPS[0] = 0;
		while(i < len) {
		    if(s[i] == s[length])
		        LPS[i++] = ++length;
		    else {
		        if(length != 0)
		            length = LPS[length - 1];
		        else
		            LPS[i++] = 0;
		    }
		}
		printf("%d\n", len % (len - LPS[len - 1]) == 0 ? len - LPS[len - 1] : len);
		firstCase = false;
	}
	return 0;
}
