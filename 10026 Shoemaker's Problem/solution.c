#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int jobNum, T, S;
} Job;

int compare(const void *a, const void *b) {
    Job *j1 = (Job*)a;
    Job *j2 = (Job*)b;
    return j1->T * j2->S > j1->S * j2->T;
}

int main() {
	int cases;
	scanf("%d", &cases);
	while(cases--) {
	    int N;
	    scanf("%d", &N);
	    Job jobs[N];
	    for(int i = 0; i < N; ++i) {
	        jobs[i].jobNum = i + 1;
	        scanf("%d %d", &jobs[i].T, &jobs[i].S);
	    }
	    qsort(jobs, N, sizeof(Job), compare);
	    for(int i = 0; i < N - 1; ++i)
	        printf("%d ", jobs[i].jobNum);
	    printf("%d\n", jobs[N - 1].jobNum);
	    if(cases)
	        putchar('\n');
	}
	return 0;
}
