#include <stdio.h>
#include <math.h>

void getCoordinate(double num, double *x, double *y) {
    double circle = ceil((-1 + sqrt(1 + 2 * num)) / 2);
    int len = num - 2 * (circle * circle - circle);
    int side = ceil(len / circle);
    len -= (side - 1) * circle;
    switch(side) {
        case 1:
            *x = -circle + len;
            *y = len;
            break;
        case 2:
            *x = len;
            *y = circle - len;
            break;
        case 3:
            *x = circle - len;
            *y = -len;
            break;
        case 4:
            *x = -len;
            *y = -circle + len;
    }
}

int main() {
    double a, b, a_x, a_y, b_x, b_y;
    while(scanf("%lf %lf", &a, &b) && a != -1) {
        if(a == 0 && b == 0)
            puts("0.00");
        else if(a == 0) {
            getCoordinate(b, &b_x, &b_y);
            printf("%.2f\n", sqrt(b_x * b_x + b_y * b_y));
        } else if(b == 0) {
            getCoordinate(a, &a_x, &a_y);
            printf("%.2f\n", sqrt(a_x * a_x + a_y * a_y));
        } else {
            getCoordinate(a, &a_x, &a_y);
            getCoordinate(b, &b_x, &b_y);
            printf("%.2f\n", sqrt((a_x - b_x) * (a_x - b_x) + (a_y - b_y) * (a_y - b_y)));
        } 
    }
    return 0;
}
