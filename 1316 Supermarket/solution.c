#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int p, d;
} Product;

int compare(const void *a, const void *b) {
    Product *p1 = (Product*)a;
    Product *p2 = (Product*)b;
    return p1->d > p2->d;
}

int main() {
    int n;
    while(scanf("%d", &n) == 1) {
        Product products[n];
        for(int i = 0; i < n; ++i)
            scanf("%d %d", &products[i].p, &products[i].d);
        qsort(products, n, sizeof(Product), compare);
        int *priorityQueue = NULL, size = 0;
        for(int i = 0; i < n; ++i) {
            if(products[i].d > size) {
                priorityQueue = (int*)realloc(priorityQueue, (size + 1) * sizeof(int));
                priorityQueue[size++] = products[i].p;
            } else {
                int minIndex = 0;
                for(int j = 1; j < size; ++j) {
                    if(priorityQueue[j] < priorityQueue[minIndex])
                        minIndex = j;
                }
                priorityQueue[minIndex] = priorityQueue[minIndex] > products[i].p ? priorityQueue[minIndex] : products[i].p;
            }
        }
        int profit = 0;
        for(int i = 0; i < size; ++i)
            profit += priorityQueue[i];
        printf("%d\n", profit);
        free(priorityQueue);
    }
	return 0;
}
