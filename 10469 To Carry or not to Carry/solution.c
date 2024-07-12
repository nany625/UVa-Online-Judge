#include <stdio.h>

int main() {
	int num1, num2;
	while(scanf("%d %d", &num1, &num2) == 2)
	    printf("%d\n", num1 ^ num2);
	return 0;
}
