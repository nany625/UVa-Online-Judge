#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    float x1, y1, x2, y2;
} Rectangle;

int main() {
    Rectangle *rec = NULL;
    int size = 0;
    while(getchar() == 'r') {
        rec = (Rectangle*)realloc(rec, (size + 1) * sizeof(Rectangle));
        scanf("%f %f %f %f ", &rec[size].x1, &rec[size].y1, &rec[size].x2, &rec[size].y2);
        ++size;
    }
    int point = 0;
    float x, y;
    while(scanf("%f %f", &x, &y) && (10 * x != 99999 || 10 * y != 99999)) {
        ++point;
        bool contained = false;
        for(int i = 0; i < size; ++i) {
            if(x > rec[i].x1 && y < rec[i].y1 && x < rec[i].x2 && y > rec[i].y2) {
                printf("Point %d is contained in figure %d\n", point, i + 1);
                contained = true;
            }
        }
        if(!contained)
            printf("Point %d is not contained in any figure\n", point);
    }
    free(rec);
	return 0;
}
