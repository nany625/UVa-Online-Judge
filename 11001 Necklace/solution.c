#include <stdio.h>

int main() {
    double V, Vo;
	while(scanf("%lf %lf", &V, &Vo) && V != 0 && Vo != 0) {
		if(V <= Vo)
		    puts("0");
		else {
		    double discs = V / 2 / Vo;
		    if(discs - (int)discs == 0.5)
		        puts("0");
		    else if(discs - (int)discs < 0.5)
           		printf("%d\n", (int)discs);
           	else
           		printf("%d\n", (int)discs + 1);
		}
	}
	return 0;
}
