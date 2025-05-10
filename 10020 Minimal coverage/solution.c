#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int L, R;
} Segment;

Segment segments[100000];

int compare(const void *a, const void *b) {
    return ((Segment*)a)->L > ((Segment*)b)->L;
}

int main() {
    int cases;
    scanf("%d", &cases);
    while(cases--) {
        int M;
        scanf("%d", &M);
        int size = 0;
        int L, R;
        while(scanf("%d %d", &L, &R) && (L != 0 || R != 0))
            segments[size++] = (Segment){L, R};
        qsort(segments, size, sizeof(Segment), compare);
        int *indices = NULL, count = 0;
        R = 0;
        for(int i = 0; i < size && R < M; ++i) {
            if(segments[i].L <= R && segments[i].R > R) {
                int maxIndex = i, j = i + 1;
                while(j < size && segments[j].L <= R) {
                    if(segments[j].R > segments[maxIndex].R)
                        maxIndex = j;
                    ++j;
                }
                indices = (int*)realloc(indices, (count + 1) * sizeof(int));
                R = segments[indices[count++] = maxIndex].R;
                i = j - 1;
            }
        }
        if(R < M)
            puts("0");
        else {
            printf("%d\n", count);
            for(int i = 0; i < count; ++i)
                printf("%d %d\n", segments[indices[i]].L, segments[indices[i]].R);
        }
        free(indices);
        if(cases)
            putchar('\n');
    }
	return 0;
}
