#include <stdio.h>
#include <string.h>

int main() {
    char s[1000001];
	while(scanf("%s", s) && s[0] != '.') {
		int len = strlen(s), LPS[len], i = 1, length = 0;
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
		printf("%d\n", len % (len - LPS[len - 1]) == 0 ? len / (len - LPS[len - 1]) : 1);
	}
	return 0;
}
