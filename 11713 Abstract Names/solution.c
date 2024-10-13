#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

int main() {
	int n;
	scanf("%d", &n);
	char realName[21], gameName[21];
	while(n--) {
	    scanf("%s %s", realName, gameName);
	    int len = strlen(realName);
	    if(len == strlen(gameName)) {
	        bool same = true;
	        for(int i = 0; i < len && same; ++i) {
	            if(isVowel(realName[i]) != isVowel(gameName[i]) || (!isVowel(realName[i]) && realName[i] != gameName[i])) {
	                puts("No");
	                same = false;
	            }
	        }
	        if(same)
	            puts("Yes");
	    } else
	        puts("No");
	}
	return 0;
}
