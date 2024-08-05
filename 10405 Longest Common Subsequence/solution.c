#include <stdio.h>
#include <string.h>

int main() {
	char str1[1002], str2[1002];
	while(fgets(str1, sizeof(str1), stdin) && fgets(str2, sizeof(str2), stdin)) {
	    str1[strcspn(str1, "\n")] = '\0';
	    str2[strcspn(str2, "\n")] = '\0';
	    int len1 = strlen(str1), len2 = strlen(str2);
	    int L[len1 + 1][len2 + 1];
	    for(int i = 0; i <= len1; ++i) {
	        for(int j = 0; j <= len2; ++j) {
	            if(i == 0 || j == 0)
	                L[i][j] = 0;
	            else if(str1[i - 1] == str2[j - 1])
	                L[i][j] = L[i - 1][j - 1] + 1;
	            else
	                L[i][j] = L[i - 1][j] > L[i][j - 1] ? L[i - 1][j] : L[i][j - 1];
	        }
	    }
	    printf("%d\n", L[len1][len2]);
	}
	return 0;
}
