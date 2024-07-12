#include <stdio.h>
#include <stdlib.h>

int main() {
	char *num = NULL;
	while(scanf("%ms", &num) && num[0] != '-') {
	    if(num[1] == 'x')
	        printf("%ld\n", strtol(num, NULL, 16));
	    else
	        printf("0x%X\n", atoi(num));
        free(num);
        num = NULL;
	}
    free(num);
	return 0;
}
