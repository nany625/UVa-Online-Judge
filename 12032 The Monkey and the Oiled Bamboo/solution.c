#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    char *buffer = NULL;
    size_t bufsize = 0;
    for(int i = 1; i <= T; ++i) {
        int n;
        scanf("%d ", &n);
        getline(&buffer, &bufsize, stdin);
        char *token = strtok(buffer, " ");
        int ans = atoi(token), k = ans - 1, prev = ans;
        token = strtok(NULL, " ");
        while(token) {
            int curr = atoi(token);
            if(curr - prev == k)
                --k;
            else if(curr - prev > k) {
                if(ans >= curr - prev)
                    k = ++ans;
                else {
                    ans = curr - prev;
                    k = ans - 1;
                }
            }
            prev = curr;
            token = strtok(NULL, " ");
        }
        printf("Case %d: %d\n", i, ans);
    }
    free(buffer);
    return 0;
}
