#include <stdio.h>
#include <string.h>

int value[256];

int main() {
    int N;
    scanf("%d", &N);
    char buffer[10002];
    while(N--) {
        int K;
        scanf("%d", &K);
        memset(value, 0, sizeof(value));
        while(K--) {
            unsigned char ch;
            int v;
            scanf(" %c %d", &ch, &v);
            value[ch] = v;
        }
        int M;
        scanf("%d", &M);
        getchar();
        int money = 0;
        while(M--) {
            fgets(buffer, sizeof(buffer), stdin);
            buffer[strcspn(buffer, "\n")] = '\0';
            int len = strlen(buffer);
            for(int i = 0; i < len; ++i)
                money += value[(unsigned char)buffer[i]];
        }
        printf("%d.%02d$\n", money / 100, money % 100);
    }
	return 0;
}
