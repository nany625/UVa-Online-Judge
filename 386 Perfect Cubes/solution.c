#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define MAX_NUM 8000000

typedef struct {
    int a, b, c, d;
} Answer;

Answer *answers;
int size;

int compare(const void *a, const void *b) {
    return ((Answer*)a)->a > ((Answer*)b)->a;
}

int main() {
    int limitB = cbrt(MAX_NUM / 3), limitC = cbrt(MAX_NUM >> 1);
	for(int b = 2; b <= limitB; ++b) {
	    for(int c = b; c <= limitC; ++c) {
	        for(int d = c, cubeA; (cubeA = b * b * b + c * c * c + d * d * d) <= MAX_NUM; ++d) {
	            int a = round(cbrt(cubeA));
	            if(a * a * a == cubeA) {
	                answers = (Answer*)realloc(answers, (size + 1) * sizeof(Answer));
	                answers[size++] = (Answer){a, b, c, d};
	            }
	        }
	    }
	}
	qsort(answers, size, sizeof(Answer), compare);
	for(int i = 0; i < size; ++i)
	    printf("Cube = %d, Triple = (%d,%d,%d)\n", answers[i].a, answers[i].b, answers[i].c, answers[i].d);
	free(answers);
	return 0;
}
