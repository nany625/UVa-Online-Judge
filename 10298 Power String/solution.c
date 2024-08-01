#include <stdio.h>
#include <string.h>

int main() {
    char s[1000001];
	while(scanf("%s", s) && s[0] != '.') {
		int len = strlen(s), lps[len], i = 1, length = 0;
		lps[0] = 0;
		while(i < len) {
		    if(s[i] == s[length])
		        lps[i++] = ++length;
		    else {
		        if(length != 0)
		            length = lps[length - 1];
		        else
		            lps[i++] = 0;
		    }
		}
		printf("%d\n", len % (len - lps[len - 1]) == 0 ? len / (len - lps[len - 1]) : 1);
	}
	return 0;
}
