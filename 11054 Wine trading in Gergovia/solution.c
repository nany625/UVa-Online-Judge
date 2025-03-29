#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int n;
	char *buffer = NULL;
	size_t bufsize = 0;
	while(scanf("%d ", &n) && n != 0) {
	    getline(&buffer, &bufsize, stdin);
	    char *token = strtok(buffer, " ");
	    long work = 0;
	    int curr = 0;
	    while(token) {
	        curr += atoi(token);
	        work += abs(curr);
	        token = strtok(NULL, " ");
	    }
	    printf("%ld\n", work);
	}
	free(buffer);
	return 0;
}
