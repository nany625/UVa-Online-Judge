#include <stdio.h>
#include <math.h>
#include <stdbool.h>

typedef struct {
    float x, y;
} Coordinate;

float dist(Coordinate i, Coordinate j) {
    return hypotf(i.x - j.x, i.y - j.y);
}

int main() {
    int n;
    while(scanf("%d", &n) == 1) {
        Coordinate gopher, dog, holes[n];
        scanf("%f %f %f %f", &gopher.x, &gopher.y, &dog.x, &dog.y);
        for(int i = 0; i < n; ++i)
            scanf("%f %f", &holes[i].x, &holes[i].y);
        bool escape = false;
        for(int i = 0; i < n && !escape; ++i) {
            if(2 * dist(gopher, holes[i]) <= dist(dog, holes[i])) {
                printf("The gopher can escape through the hole at (%.3f,%.3f).\n", holes[i].x, holes[i].y);
                escape = true;
            }
        }
        if(!escape)
            puts("The gopher cannot escape.");
    }
	return 0;
}
