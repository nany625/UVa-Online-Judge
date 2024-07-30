#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int N;
    scanf("%d", &N);
    getchar();
    char *buffer = NULL;
    size_t bufsize = 0;
    while(N--) {
        getline(&buffer, &bufsize, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        long min = 0, prev = 0;
        int next = 1, len = strlen(buffer);
        bool add = true;
        for(int i = 0; i < len; ++i) {
            switch(buffer[i]) {
                case '+':
                    add = true;
                    min += prev * next;
                    prev = 0;
                    next = 1;
                    break;
                case '*':
                    add = false;
                    prev *= next;
                    next = 0;
                    break;
                default:
                    if(add)
                        prev = 10 * prev + buffer[i] - '0';
                    else
                        next = 10 * next + buffer[i] - '0';
            }
        }
        min += prev * next;
        long max = 1;
        prev = 0;
        next = 0;
        add = false;
        for(int i = 0; i < len; ++i) {
            switch(buffer[i]) {
                case '+':
                    add = true;
                    prev += next;
                    next = 0;
                    break;
                case '*':
                    add = false;
                    max *= (prev + next);
                    prev = 0;
                    next = 0;
                    break;
                default:
                    if(!add)
                        prev = 10 * prev + buffer[i] - '0';
                    else
                        next = 10 * next + buffer[i] - '0';
            }
        }
        max *= (prev + next);
        printf("The maximum and minimum are %ld and %ld.\n", max, min);
    }
    free(buffer);
	return 0;
}
