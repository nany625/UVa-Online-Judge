#include <stdio.h>
#include <string.h>
#define MAX_LEN 2000000

int main() {
    int L;
    char S[MAX_LEN + 1];
    while(scanf("%d", &L) && L != 0) {
        scanf("%s", S);
        int min = MAX_LEN, prev, len = strlen(S);
        char last = 'Z';
        for(int i = 0; i < len && min > 0; ++i) {
            if(S[i] == 'R') {
                if(last == 'D')
                    min = min < i - prev ? min : i - prev;
                prev = i;
                last = 'R';
            } else if(S[i] == 'D') {
                if(last == 'R')
                    min = min < i - prev ? min : i - prev;
                prev = i;
                last = 'D';
            } else if(S[i] == 'Z')
                min = 0;
        }
        printf("%d\n", min == MAX_LEN ? 0 : min);
    }
    return 0;
}
