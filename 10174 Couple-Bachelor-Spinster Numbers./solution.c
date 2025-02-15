#include <stdio.h>
#include <stdlib.h>

int main() {
    int n1, n2;
    char *buffer = NULL;
    size_t bufsize = 0;
    while(getline(&buffer, &bufsize, stdin) != -1) {
        if(sscanf(buffer, "%d %d", &n1, &n2) == 1) {
            if((n1 & 3) == 2)
                puts("Bachelor Number.");
            else if(n1 & 1)
                printf("%d %d\n", abs((n1 >> 1) + 1), abs(n1 >> 1));
            else
                printf("%d %d\n", abs((n1 >> 2) + 1), abs((n1 >> 2) - 1));
        } else {
            while((n1 & 3) != 2)
                ++n1;
            while((n2 & 3) != 2)
                --n2;
            printf("%d\n", (n2 - n1 >> 2) + 1);
        }
    }
    free(buffer);
    return 0;
}
