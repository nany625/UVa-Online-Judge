#include <stdio.h>
#define MAX_NUM 100000

int root[(MAX_NUM << 1) + 1], elements[(MAX_NUM << 1) + 1];
long sum[(MAX_NUM << 1) + 1];

int find(int x) {
    return root[x] == x ? x : (root[x] = find(root[x]));
}

int main() {
    int n, m;
    while(scanf("%d %d", &n, &m) == 2) {
        for(int i = 1; i <= n; ++i) {
            root[i] = root[i + n] = i + n;
            elements[i] = elements[i + n] = 1;
            sum[i] = sum[i + n] = i;
        }
        while(m--) {
            int command, p, q, rootP, rootQ;
            scanf("%d", &command);
            switch(command) {
                case 1:
                    scanf("%d %d", &p, &q);
                    rootP = find(p);
                    rootQ = find(q);
                    if(rootP != rootQ) {
                        root[rootQ] = rootP;
                        elements[rootP] += elements[rootQ];
                        sum[rootP] += sum[rootQ];
                    }
                    break;
                case 2:
                    scanf("%d %d", &p, &q);
                    rootP = find(p);
                    rootQ = find(q);
                    if(rootP != rootQ) {
                        root[p] = rootQ;
                        --elements[rootP];
                        ++elements[rootQ];
                        sum[rootP] -= p;
                        sum[rootQ] += p;
                    }
                    break;
                case 3:
                    scanf("%d", &p);
                    rootP = find(p);
                    printf("%d %ld\n", elements[rootP], sum[rootP]);
            }
        }
    }
	return 0;
}
