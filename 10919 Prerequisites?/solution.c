#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool selected[10000];

int main() {
    int k;
    while(scanf("%d", &k) && k != 0) {
        int m;
        scanf("%d", &m);
        memset(selected, 0, sizeof(selected));
        while(k--) {
            int courseNum;
            scanf("%d", &courseNum);
            selected[courseNum] = true;
        }
        bool graduate = true;
        while(m--) {
            int r, c;
            scanf("%d %d", &r, &c);
            while(r--) {
                int courseNum;
                scanf("%d", &courseNum);
                c -= selected[courseNum];
            }
            if(c > 0)
                graduate = false;
        }
        puts(graduate ? "yes" : "no");
    }
    return 0;
}
