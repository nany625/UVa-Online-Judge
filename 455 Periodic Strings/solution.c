#include <stdio.h>
#include <string.h>

int main() {
	int N;
	scanf("%d", &N);
	char s[81];
	while(N--) {
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
		if(N)
            putchar('\n');
	}
	return 0;
}
