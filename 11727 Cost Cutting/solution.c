#include <stdio.h>

short salary[3];

void swap(short *a, short *b) {
    short temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        for(int j = 0; j < 3; ++j)
            scanf("%hd", &salary[j]);
        if(salary[0] > salary[1])
            swap(&salary[0], &salary[1]);
        if(salary[1] > salary[2])
            swap(&salary[1], &salary[2]);
        printf("Case %d: %d\n", i, salary[0] > salary[1] ? salary[0] : salary[1]);
    }
	return 0;
}
