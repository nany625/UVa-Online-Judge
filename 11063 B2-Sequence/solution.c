#include <stdio.h>
#include <stdbool.h>

int main() {
    int cases = 0, N;
    while(scanf("%d", &N) == 1) {
        short b[N];
        for(int i = 0; i < N; ++i)
            scanf("%hd", &b[i]);
        bool isB2 = true;
        for(int i = 0; i < N - 1 && isB2; ++i) {
            if(b[i] < 1 || b[i] >= b[i + 1])
                isB2 = false;
        }
        if(!isB2)
            printf("Case #%d: It is not a B2-Sequence.\n\n", ++cases);
        else {
            bool diff[b[N - 1] - b[0]];
            for(int i = 0; i < b[N - 1] - b[0]; ++i)
                diff[i] = false;
            for(int i = 0; i < N - 1 && isB2; ++i) {
                for(int j = i + 1; j < N && isB2; ++j) {
                    if(!diff[b[j] - b[i] - 1])
                        diff[b[j] - b[i] - 1] = true;
                    else
                        isB2 = false;
                }
            }
            printf("Case #%d: It is %sa B2-Sequence.\n\n", ++cases, isB2 ? "" : "not ");
        }
    }
    return 0;
}
