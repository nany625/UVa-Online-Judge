#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    char *buffer = NULL;
    size_t bufsize = 0;
    while(T--) {
        int n;
        scanf("%d ", &n);
        getline(&buffer, &bufsize, stdin);
        char *token = strtok(buffer, " ");
        int C[n];
        for(int i = 0; i < n; ++i) {
            C[i] = atoi(token);
            token = strtok(NULL, " ");
        }
        int sum = 0, count = 1;
        for(int i = 1; i < n; ++i) {
            if(sum + C[i - 1] < C[i]) {
                sum += C[i - 1];
                ++count;
            }
        }
        printf("%d\n", count);
    }
    free(buffer);
	return 0;
}
