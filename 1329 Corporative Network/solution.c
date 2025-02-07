#include <stdio.h>
#include <stdlib.h>
#define MAX_NUM 20000

int root[MAX_NUM + 1], length[MAX_NUM + 1];

int findRoot(int child) {
    if(root[child] != child) {
        int temp = findRoot(root[child]);
        length[child] += length[root[child]];
        return root[child] = temp;
    }
    return child;
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
                findRoot(I);
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
