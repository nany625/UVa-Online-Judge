#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *num = NULL;
	while(scanf("%ms", &num) && num[0] != '-') {
	    if(strlen(num) > 2 && num[1] == 'x')
	        printf("%ld\n", strtol(num, NULL, 16));
	    else
	        printf("0x%X\n", atoi(num));
        free(num);
        num = NULL;
	}
    free(num);
	return 0;
}
