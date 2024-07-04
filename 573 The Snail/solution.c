#include <stdio.h>

int main() {
	float H, U, D, F;
	while(scanf("%f %f %f %f", &H, &U, &D, &F) && H != 0) {
		int day = 0;
		float curr = 0, lost = U * F / 100;
		do {
			++day;
			curr += U;
			if(curr > H)
				break;
			curr -= D;
			U = U >= lost ? U - lost : 0;
		} while(curr >= 0);
		printf("%s on day %d\n", curr > H ? "success" : "failure", day);
	}
	return 0;
}
