#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    char **dreams = NULL, query[6];
    int size = 0;
    while(n--) {
        scanf("%s", query);
        switch(query[0]) {
            case 'S':
                dreams = (char**)realloc(dreams, (size + 1) * sizeof(char*));
                scanf("%ms", &dreams[size++]);
                break;
            case 'K':
                if(size > 0) {
                    free(dreams[--size]);
                    dreams = (char**)realloc(dreams, size * sizeof(char*));
                }
                break;
            case 'T':
                if(size > 0)
                    printf("%s\n", dreams[size - 1]);
                else
                    puts("Not in a dream");
        }
    }
    for(int i = 0; i < size; ++i)
        free(dreams[i]);
    free(dreams);
	return 0;
}
