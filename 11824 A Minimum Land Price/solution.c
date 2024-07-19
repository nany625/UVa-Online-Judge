#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int compare(const void *a, const void *b) {
    return *(int*)b - *(int*)a;
}

int main() {
    int T;
	scanf("%d", &T);
	while(T--) {
	    int *cost = NULL, size = 0, L;
	    while(scanf("%d", &L) && L != 0) {
	        cost = (int*)realloc(cost, (size + 1) * sizeof(int));
	        cost[size++] = L;
	    }
	    qsort(cost, size, sizeof(int), compare);
	    int total = 0;
	    for(int i = 0; i < size && total <= 5000000; ++i)
	        total += 2 * pow(cost[i], i + 1);
	    if(total <= 5000000)
	        printf("%d\n", total);
	    else
	    	puts("Too expensive");
	    free(cost);
	}
    return 0;
}
