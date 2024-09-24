#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int GCD(int i, int j) {
    return j == 0 ? i : GCD(j, i % j);
}

int main() {
	int N;
	scanf("%d", &N);
	getchar();
	char *buffer = NULL;
	size_t bufsize = 0;
	while(N--) {
	    getline(&buffer, &bufsize, stdin);
	    char *token = strtok(buffer, " \n");
	    int *numbers = NULL, size = 0;
	    while(token) {
	        numbers = (int*)realloc(numbers, (size + 1) * sizeof(int));
	        numbers[size++] = atoi(token);
	        token = strtok(NULL, " \n");
	    }
	    int max = 1;
	    for(int i = 0; i < size - 1; ++i) {
	        for(int j = i + 1; j < size; ++j) {
	            int temp = GCD(numbers[i], numbers[j]);
	            max = max > temp ? max : temp;
	        }
	    }
	    printf("%d\n", max);
	    free(numbers);
	}
	free(buffer);
	return 0;
}
