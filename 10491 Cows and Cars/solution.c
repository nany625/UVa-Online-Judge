#include <stdio.h>

int main() {
    double NCOWS, NCARS, NSHOW;
    while(scanf("%lf %lf %lf", &NCOWS, &NCARS, &NSHOW) == 3)
        printf("%.5f\n", NCOWS / (NCOWS + NCARS) * NCARS / (NCOWS + NCARS - NSHOW - 1) + NCARS / (NCOWS + NCARS) * (NCARS - 1) / (NCOWS + NCARS - NSHOW - 1));
	return 0;
}
