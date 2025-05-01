#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        printf("Case %d\n", i);
        char *sprinkler = NULL;
        scanf("%ms", &sprinkler);
        int trails[26] = {}, len = strlen(sprinkler), stack[len], size = 1;
        stack[0] = sprinkler[0];
        for(int j = 1; j < len; ++j) {
            if(sprinkler[j] != stack[size - 1]) {
                ++trails[stack[size - 1] - 'A'];
                ++trails[sprinkler[j] - 'A'];
                stack[size++] = sprinkler[j];
            } else
                --size;
        }
        for(int j = 0; j < 26; ++j) {
            if(trails[j] > 0)
                printf("%c = %d\n", 'A' + j, trails[j]);
        }
        free(sprinkler);
    }
	return 0;
}
