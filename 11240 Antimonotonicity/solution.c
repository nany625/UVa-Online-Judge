#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    char *buffer = NULL;
    size_t bufsize = 0;
    while(T--) {
        int prev, size = 1;
        scanf("%*d %d", &prev);
        getline(&buffer, &bufsize, stdin);
        char *token = strtok(buffer, " ");
        while(token) {
            int curr = atoi(token);
            size += (size & 1) == curr < prev;
            prev = curr;
            token = strtok(NULL, " ");
        }
        printf("%d\n", size);
    }
    free(buffer);
	return 0;
}
