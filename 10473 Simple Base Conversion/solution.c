#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	char *num = NULL;
	while(scanf("%ms", &num) && num[0] != '-') {
	    if(strncmp(num, "0x", 2) == 0)
	        printf("%ld\n", strtol(num, NULL, 16));
	    else
	        printf("0x%X\n", atoi(num));
	}
	return 0;
}
