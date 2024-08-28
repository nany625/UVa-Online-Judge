#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int number, mod;
} Data;

int compare(const void *a, const void *b) {
    Data *d1 = (Data*)a;
    Data *d2 = (Data*)b;
    if(d1->mod != d2->mod)
        return d1->mod > d2->mod;
    int abs1 = abs(d1->number & 1);
    int abs2 = abs(d2->number & 1);
    if(abs1 + abs2 == 1)
        return abs1 != 1;
    if(abs1 == 1)
        return d1->number < d2->number;
    return d1->number > d2->number;
}

int main() {
	int N, M;
	while(scanf("%d %d", &N, &M) && N != 0 && M != 0) {
	    printf("%d %d\n", N, M);
	    Data datas[N];
	    for(int i = 0; i < N; ++i) {
	        scanf("%d", &datas[i].number);
	        datas[i].mod = datas[i].number % M;
	    }
	    qsort(datas, N, sizeof(Data), compare);
	    for(int i = 0; i < N; ++i)
	        printf("%d\n", datas[i].number);
	}
	puts("0 0");
	return 0;
}
