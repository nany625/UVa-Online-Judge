#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int*)a > *(int*)b;
}

int main() {
    int lengths[3];
    while(scanf("%d %d %d", &lengths[0], &lengths[1], &lengths[2]) && lengths[0] != 0) {
        qsort(lengths, 3, sizeof(int), compare);
        puts(lengths[0] * lengths[0] + lengths[1] * lengths[1] == lengths[2] * lengths[2] ? "right" : "wrong");
    }
	return 0;
}
