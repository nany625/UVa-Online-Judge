#include <stdio.h>
#include <stdbool.h>
#define MAX_NUM 5000000

bool isComposite[MAX_NUM + 1] = {true, true};
int sum[MAX_NUM + 1], count[MAX_NUM + 1];

int main() {
    for(int i = 2; i <= MAX_NUM; ++i) {
        if(!isComposite[i]) {
            for(int j = i; j <= MAX_NUM; j += i)
                sum[j] += i;
            if(i <= 2236) {
                for(int j = i * i; j <= MAX_NUM; j += i)
                    isComposite[j] = true;
            }
        }
        count[i] = count[i - 1] + !isComposite[sum[i]];
    }
    int a;
    while(scanf("%d", &a) && a != 0) {
        int b;
        scanf("%d", &b);
        printf("%d\n", count[b] - count[a] + !isComposite[sum[a]]);
    }
    return 0;
}
