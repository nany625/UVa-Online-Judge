#include <stdio.h>
#include <math.h>

int main() {
	int H, M;
	while(scanf("%d %*c %d", &H, &M) && (H != 0 || M != 0)) {
	    float degree = fabs((H %= 12) * 30 + M / 2.0 - M * 6);
	    if(degree > 180)
	        degree = 360 - degree;
        printf("%.3f\n", degree);
	}
	return 0;
}
