#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *buffer = NULL;
    size_t bufsize = 0;
    while(getline(&buffer, &bufsize, stdin) != -1) {
        char *token = strtok(buffer, " ");
        char *m = strdup(token);
        token = strtok(NULL, " ");
        char op = token[0];
        token = strtok(NULL, " ");
        int divider = atoi(token);
        int len = strlen(m);
        if(op == '/') {
            long dividend = 0;
            char *quotient = NULL;
            int size = 0;
            for(int i = 0; i < len; ++i) {
                dividend = 10 * dividend + m[i] - '0';
                if(size > 0 || dividend >= divider) {
                    quotient = (char*)realloc(quotient, (size + 2) * sizeof(char));
                    quotient[size++] = dividend / divider + '0';
                }
                dividend %= divider;
            }
            if(size == 0)
                puts("0");
            else {
                quotient[size] = '\0';
                puts(quotient);
            }
            free(quotient);
        } else if(op == '%') {
            long dividend = 0;
            for(int i = 0; i < len; ++i)
                dividend = (10 * dividend + m[i] - '0') % divider;
            printf("%ld\n", dividend);
        }
        free(m);
        m = NULL;
    }
    free(buffer);
	return 0;
}
