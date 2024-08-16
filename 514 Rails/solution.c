#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int N;
    char *buffer = NULL;
    size_t bufsize = 0;
    while(scanf("%d", &N) && N != 0) {
        int prev;
        while(scanf("%d", &prev) && prev != 0) {
            int max = prev;
            getline(&buffer, &bufsize, stdin);
            char *token = strtok(buffer, " ");
            bool YES = true;
            while(token && YES) {
                int curr = atoi(token);
                if(curr > prev && curr < max)
                    YES = false;
                else {
                    prev = curr;
                    max = max > curr ? max : curr;
                    token = strtok(NULL, " ");
                }
            }
            puts(YES ? "Yes" : "No");
        }
        putchar('\n');
    }
    free(buffer);
    return 0;
}
