#include <stdio.h>
#include <string.h>

int main() {
	char str1[1002], str2[1002];
	while(fgets(str1, sizeof(str1), stdin) && fgets(str2, sizeof(str2), stdin)) {
	    str1[strcspn(str1, "\n")] = '\0';
	    str2[strcspn(str2, "\n")] = '\0';
	    int len1 = strlen(str1), len2 = strlen(str2);
	    int L[len2 + 1];
	    for(int i = 0; i <= len2; ++i)
	        L[i] = 0;
	    for(int i = 0; i < len1; ++i) {
	        int prev = 0;
	        for(int j = 1; j <= len2; ++j) {
	            int temp = L[j];
	            if(str1[i] == str2[j - 1])
	                L[j] = prev + 1;
	            else
	                L[j] = L[j] > L[j - 1] ? L[j] : L[j - 1];
	            prev = temp;
	        }
	    }
	    printf("%d\n", L[len2]);
	}
	return 0;
}
