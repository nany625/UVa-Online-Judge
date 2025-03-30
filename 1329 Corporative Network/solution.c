#include <stdio.h>
#include <stdlib.h>
#define MAXN 20000

int root[MAXN + 1], length[MAXN + 1];

int find(int x) {
    if(root[x] != x) {
        int temp = find(root[x]);
        length[x] += length[root[x]];
        return root[x] = temp;
    }
    return x;
}

int main() {
    int T;
    scanf("%d ", &T);
    while(T--) {
        int N;
        scanf("%d ", &N);
        for(int n = 1; n <= N; ++n)
            length[root[n] = n] = 0;
        char command;
        while((command = getchar()) != 'O') {
            if(command == 'E') {
                int I;
                scanf("%d ", &I);
                find(I);
                printf("%d\n", length[I]);
            } else {
                int I, J;
                scanf("%d %d ", &I, &J);
                root[I] = J;
                length[I] = abs(I - J) % 1000;
            }
        }
    }
    return 0;
}
