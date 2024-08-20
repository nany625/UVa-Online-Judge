#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer = NULL;
    size_t bufsize = 0;
    while(getline(&buffer, &bufsize, stdin) != -1) {
        char *token = strtok(buffer, " ");
        int max = atoi(token), curr = atoi(token);
        token = strtok(NULL, " ");
        while(token) {
            int temp = atoi(token);
            curr = temp > curr + temp ? temp : curr + temp;
            max = max > curr ? max : curr;
            token = strtok(NULL, " ");
        }
        printf("%d\n", max >= 0 ? max : 0);
    }
    free(buffer);
	return 0;
}
