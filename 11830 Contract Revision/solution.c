#include <stdio.h>
#include <string.h>

int main() {
    char D, N[101], temp[101];
    while(scanf("%c ", &D) && D != '0') {
        scanf("%s ", N);
        int size = 0, len = strlen(N);
        for(int i = 0; i < len; ++i) {
            if(D != N[i])
                temp[size++] = N[i];
        }
        temp[size] = '\0';
        int i = 0;
        while(i < size && temp[i] == '0')
            ++i;
        if(i == size)
            puts("0");
        else
            puts(temp + i);
    }
    return 0;
}
