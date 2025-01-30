#include <stdio.h>
#include <string.h>

int main() {
    int k;
    scanf("%d", &k);
    char S[100001], T[1001];
    while(k--) {
        scanf("%s", S);
        int q;
        scanf("%d", &q);
        while(q--) {
            scanf("%s", T);
            puts(strstr(S, T) ? "y" : "n");
        }
    }
	return 0;
}
