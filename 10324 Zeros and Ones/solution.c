#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int cases = 0;
    char *buffer = NULL;
    while(scanf("%ms", &buffer) == 1) {
        printf("Case %d:\n", ++cases);
        int len = strlen(buffer), groups[len];
        for(int i = 1; i < len; ++i)
            groups[i] = groups[i - 1] + (buffer[i] != buffer[i - 1]);
        int n;
        scanf("%d", &n);
        while(n--) {
            int i, j;
            scanf("%d %d", &i, &j);
            puts(groups[i] == groups[j] ? "Yes" : "No");
        }
        free(buffer);
        buffer = NULL;
    }
    return 0;
}
