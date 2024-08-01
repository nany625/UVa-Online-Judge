#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int T;
    scanf("%d", &T);
    char *buffer = NULL;
    size_t bufsize = 0;
    while(T--) {
        int n, prev, size = 1;
        scanf("%d %d", &n, &prev);
        getline(&buffer, &bufsize, stdin);
        char *token = strtok(buffer, " ");
        while(token) {
            int curr = atoi(token);
            if((size % 2 == 0) == curr > prev)
                ++size;
            prev = curr;
            token = strtok(NULL, " ");
        }
        printf("%d\n", size);
    }
    free(buffer);
	return 0;
}
