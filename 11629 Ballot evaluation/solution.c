#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EPS 0.01

typedef struct {
    char name[21];
    double vote;
} Party;

int compare(const void *a, const void *b) {
    return strcmp(((Party*)a)->name, ((Party*)b)->name);
}

double binarySearch(Party *array, int size, char *key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left >> 1);
        int cmp = strcmp(array[mid].name, key);
        if(cmp == 0)
            return array[mid].vote;
        if(cmp < 0)
            left = mid + 1;
        else
            right = mid - 1;
    }
}

int main() {
    int p, g;
    scanf("%d %d", &p, &g);
    Party parties[p];
    for(int i = 0; i < p; ++i)
        scanf("%s %lf", parties[i].name, &parties[i].vote);
    qsort(parties, p, sizeof(Party), compare);
    char P[21];
    int n;
    for(int i = 1; i <= g; ++i) {
        double sum = 0;
        while(scanf("%s", P)) {
            if(strcmp(P, "<") == 0) {
                scanf("%d", &n);
                printf("Guess #%d was %s.\n", i, sum + EPS < n ? "correct" : "incorrect");
                break;
            } else if(strcmp(P, ">") == 0) {
                scanf("%d", &n);
                printf("Guess #%d was %s.\n", i, sum - EPS > n ? "correct" : "incorrect");
                break;
            } else if(strcmp(P, "<=") == 0) {
                scanf("%d", &n);
                printf("Guess #%d was %s.\n", i, sum - EPS <= n ? "correct" : "incorrect");
                break;
            } else if(strcmp(P, ">=") == 0) {
                scanf("%d", &n);
                printf("Guess #%d was %s.\n", i, sum + EPS >= n ? "correct" : "incorrect");
                break;
            } else if(strcmp(P, "=") == 0) {
                scanf("%d", &n);
                printf("Guess #%d was %s.\n", i, abs(sum - n) < EPS ? "correct" : "incorrect");
                break;
            } else if(P[0] == '+')
                continue;
            else
                sum += binarySearch(parties, p, P);
        }
    }
    return 0;
}
