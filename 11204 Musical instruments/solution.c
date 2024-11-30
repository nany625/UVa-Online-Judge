#include <stdio.h>
#include <string.h>

int main() {
    int cases;
    scanf("%d", &cases);
    while(cases--) {
        int N, M;
        scanf("%d %d", &N, &M);
        int priority[N];
        memset(priority, 0, sizeof(priority));
        while(M--) {
            for(int i = 0; i < N; ++i) {
                int temp;
                scanf("%d", &temp);
                if(temp == 1)
                    ++priority[i];
            }
        }
        int distribution = 1;
        for(int i = 0; i < N; ++i) {
            if(priority[i] > 0)
                distribution *= priority[i];
        }
        printf("%d\n", distribution);
    }
    return 0;
}
