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
        char message[n + 1];
        while(scanf("%d", &k) && k != 0) {
            getchar();
            char ch;
            int i = 0;
            while((ch = getchar()) != '\n')
                message[i++] = ch;
            while(i < n)
                message[i++] = ' ';
            char cipher[n + 1];
            cipher[n] = '\0';
            int nextIndex[n];
            bool visited[n];
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
            printf("%s\n", cipher);
        }
        putchar('\n');
    }
    return 0;
}
