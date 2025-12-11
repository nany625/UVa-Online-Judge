#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int Q_num, Period, next;
} Query;

Query queries[1000];
int size = 0;
char instruction[9];

int compare(const void *a, const void *b) {
    Query *q1 = (Query*)a;
    Query *q2 = (Query*)b;
    if(q1->next == q2->next)
        return q1->Q_num > q2->Q_num;
    return q1->next > q2->next;
}

int main() {
    while(scanf("%s", instruction) && instruction[0] != '#') {
        scanf("%d %d", &queries[size].Q_num, &queries[size].Period);
        queries[size].next = queries[size].Period;
        ++size;
    }
    qsort(queries, size, sizeof(Query), compare);
    int K;
    scanf("%d", &K);
    while(K--) {
        printf("%d\n", queries[0].Q_num);
        queries[0].next += queries[0].Period;
        int i = 0;
        while(i < size - 1) {
            if(queries[i].next > queries[i + 1].next || (queries[i].next == queries[i + 1].next && queries[i].Q_num > queries[i + 1].Q_num)) {
                    Query temp = queries[i];
                    queries[i] = queries[i + 1];
                    queries[i + 1] = temp;
                    ++i;
            } else
                break;
        }
    }
	return 0;
}
