#include <stdio.h>
#define MAX_NUM 10000000

int fun[MAX_NUM + 1], count[MAX_NUM + 1];

int sod(int n) {
    int ans = 0;
    while(n > 0) {
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int main() {
    for(int n = 1; n <= MAX_NUM; ++n) {
        int temp = n + sod(n);
        if(temp <= MAX_NUM && fun[temp] == 0)
            fun[temp] = n;
        count[n] = count[n - 1] + (fun[n] == 0);
    }
    int cases;
    scanf("%d ", &cases);
    char buffer[19];
    for(int i = 1; i <= cases; ++i) {
        fgets(buffer, sizeof(buffer), stdin);
        int a, b;
        if(sscanf(buffer, "%d %d", &a, &b) == 2)
            printf("Case %d: %d\n", i, count[b] - count[a - 1]);
        else {
            sscanf(buffer, "%d", &a);
            printf("Case %d: %d\n", i, fun[a] == 0 ? -1 : fun[a]);
        }
    }
    return 0;
}
