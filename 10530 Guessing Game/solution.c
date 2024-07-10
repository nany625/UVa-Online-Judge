#include <stdio.h>
#include <string.h>

int main() {
	int min = 1, max = 10, guess;
	char resp[10];
	while(scanf("%d", &guess) && guess != 0) {
	    getchar();
	    fgets(resp, sizeof(resp), stdin);
	    if(strcmp(resp, "too high\n") == 0)
	        max = max < (guess - 1) ? max : guess - 1;
	    else if(strcmp(resp, "too low\n") == 0)
	        min = min > (guess + 1) ? min : guess + 1;
	    else if(strcmp(resp, "right on\n") == 0) {
	        if(guess >= min && guess <= max)
	            puts("Stan may be honest");
	        else
	            puts("Stan is dishonest");
	        min = 1;
	        max = 10;
	    }
	}
	return 0;
}
