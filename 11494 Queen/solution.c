#include <stdio.h>
#include <stdlib.h>

int main() {
    int X1, Y1, X2, Y2;
    while(scanf("%d %d %d %d", &X1, &Y1, &X2, &Y2) && X1 + Y1 + X2 + Y2 > 0) {
        if(X1 == X2 && Y1 == Y2)
            puts("0");
        else if(X1 == X2 || Y1 == Y2 || abs(X2 - X1) ==  abs(Y2 - Y1))
            puts("1");
        else
            puts("2");
    }
	return 0;
}
