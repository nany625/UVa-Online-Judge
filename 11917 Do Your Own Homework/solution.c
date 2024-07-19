#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *name, days;
} Subject;

int compare(const void *a, const void *b) {
    return strcmp(((Subject*)a)->name, ((Subject*)b)->name);
}

const char *binarySearch(Subject *array, int size, Subject key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        int cmp = strcmp(array[mid].name, key.name);
        if(cmp == 0) {
            if(key.days >= array[mid].days)
                return "Yesss";
            if(key.days + 5 < array[mid].days)
                return "Do your own homework!";
            return "Late";
        }
        if(cmp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return "Do your own homework!";
}

int main() {
    int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) {
	    int N;
        scanf("%d", &N);
        Subject subjects[N];
        for(int j = 0; j < N; ++j) {
            subjects[j].name = NULL;
            scanf("%ms %d", &subjects[j].name, &subjects[j].days);
        }
        qsort(subjects, N, sizeof(Subject), compare);
        Subject due;
        due.name = NULL;
        scanf("%d %ms", &due.days, &due.name);
        printf("Case %d: %s\n", i, binarySearch(subjects, N, due));
        for(int j = 0; j < N; ++j)
            free(subjects[j].name);
        free(due.name);
	}
    return 0;
}
