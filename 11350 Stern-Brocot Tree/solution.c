#include <stdio.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    char s[91];
    while(N--) {
        scanf("%s", s);
        int len = strlen(s);
        long add[][2] = {{0, 1}, {1, 0}}, a = 1, b = 1;
        for(int i = 0; i < len; ++i) {
            if(s[i] == 'L') {
                a = add[0][0] + (add[0][1] = a);
                b = add[1][0] + (add[1][1] = b);
            } else {
                a = (add[0][0] = a) + add[0][1];
                b = (add[1][0] = b) + add[1][1];
            }
        }
        printf("%ld/%ld\n", a, b);
    }
    return 0;
}
