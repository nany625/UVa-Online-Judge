#include <stdio.h>
#include <string.h>

int main() {
	char str[100001];
	while(scanf("%s", str) == 1) {
	    int len = strlen(str);
	    char concat[(len << 1) + 2];
	    memset(concat + len + 1, '\0', len);
	    for(int i = 0; i < len; ++i)
	        concat[i] = str[len - 1 - i];
	    concat[len] = '#';
	    strcat(concat, str);
	    int lps[(len << 1) + 1], i = 1, length = 0;
	    lps[0] = 0;
	    while(i < (len << 1) + 1) {
	        if(concat[i] == concat[length])
	            lps[i++] = ++length;
	        else {
	            if(length != 0)
	                length = lps[length - 1];
	            else
	                lps[i++] = 0;
	        }
	    }
	    fputs(str, stdout);
	    for(int j = len - lps[len << 1] - 1; j >= 0; --j)
	        putchar(str[j]);
	    putchar('\n');
	}
	return 0;
}
