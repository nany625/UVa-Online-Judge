#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int n;
    while(scanf("%d", &n) && n != 0) {
        int secretKeys[n];
        for(int i = 0; i < n; ++i) {
            scanf("%d", &secretKeys[i]);
            --secretKeys[i];
        }
        int k;
        char message[n + 2], cipher[n + 1];
        cipher[n] = '\0';
        int nextIndex[n];
        bool visited[n];
        while(scanf("%d", &k) && k != 0) {
            getchar();
            fgets(message, sizeof(message), stdin);
            int len = strlen(message) - 1;
            memset(message + len, ' ', (n - len) * sizeof(char));
            for(int i = 0; i < n; ++i) {
                memset(visited, 0, sizeof(visited));
                visited[nextIndex[0] = i] = true;
                int cycle = 1;
                while(!visited[secretKeys[nextIndex[cycle - 1]]]) {
                    nextIndex[cycle] = secretKeys[nextIndex[cycle - 1]];
                    visited[nextIndex[cycle++]] = true;
                }
                cipher[nextIndex[k % cycle]] = message[i];
            }
            puts(cipher);
        }
        putchar('\n');
    }
    return 0;
}
