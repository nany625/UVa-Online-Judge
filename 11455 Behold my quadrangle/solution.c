#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    return *(int*)a > *(int*)b;
}

int main() {
    int sides[4], cases;
    scanf("%d", &cases);
    while(cases--) {
        for(int i = 0; i < 4; ++i)
			scanf("%d", &sides[i]);
		qsort(sides, 4, sizeof(int), compare);
		if(sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3])
			puts("square");
		else if(sides[0] == sides[1] && sides[2] == sides[3])
			puts("rectangle");
		else if(sides[0] + sides[1] + sides[2] > sides[3])
			puts("quadrangle");
		else
			puts("banana");
    }
    return 0;
}
