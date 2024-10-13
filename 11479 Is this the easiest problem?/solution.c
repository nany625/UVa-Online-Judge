#include <stdio.h>

int main() {
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) {
	    long side1, side2, side3;
	    scanf("%ld %ld %ld", &side1, &side2, &side3);
	    if(side1 + side2 > side3 && side2 + side3 > side1 && side1 + side3 > side2) {
		    if(side1 == side2 && side2 == side3)
	            printf("Case %d: Equilateral\n", i);
	        else if(side1 == side2 || side2 == side3 || side1 == side3)
	            printf("Case %d: Isosceles\n", i);
	        else
	            printf("Case %d: Scalene\n", i);
	    } else
	        printf("Case %d: Invalid\n", i);
	}
	return 0;
}
