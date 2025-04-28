#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);
    getchar();
    char *buffer = NULL, stack[128];
    size_t bufsize = 0;
    while(n--) {
        getline(&buffer, &bufsize, stdin);
        int count1 = 0, count2 = 0, size = 0, len = strlen(buffer);
        bool correct = true;
        for(int i = 0; i < len && correct; ++i) {
            if(buffer[i] == '(') {
                ++count1;
                stack[size++] = '(';
            } else if(buffer[i] == ')') {
                if(stack[size - 1] == '(') {
                    --count1;
                    --size;
                } else
                    correct = false;
            } else if(buffer[i] == '[') {
                ++count2;
                stack[size++] = '[';
            } else if(buffer[i] == ']') {
                if(stack[size - 1] == '[') {
                    --count2;
                    --size;
                } else
                    correct = false;
            }
        }
        puts(correct && count1 == 0 && count2 == 0 ? "Yes" : "No");
    }
    free(buffer);
	return 0;
}
