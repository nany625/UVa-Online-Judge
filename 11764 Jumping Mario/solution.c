#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int T;
    scanf("%d", &T);
    char *buffer = NULL;
    size_t bufsize = 0;
    for(int i = 1; i <= T; ++i) {
        scanf("%*d ");
        getline(&buffer, &bufsize, stdin);
        int highJumps = 0, lowJumps = 0, len = strlen(buffer);
        for(int j = 2; j < len; j += 2) {
            if(buffer[j] > buffer[j - 2])
                ++highJumps;
            else if(buffer[j] < buffer[j - 2])
                ++lowJumps;
        }
        printf("Case %d: %d %d\n", i, highJumps, lowJumps);
    }
    free(buffer);
    return 0;
}
