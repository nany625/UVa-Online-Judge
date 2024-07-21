#include <stdio.h>
#include <string.h>

int main() {
	int min = 1, max = 10, guess;
	char resp[10];
	while(scanf("%d", &guess) && guess != 0) {
	    getchar();
	    fgets(resp, sizeof(resp), stdin);
	    switch(resp[4]) {
	        case 'h':
	            max = max < (guess - 1) ? max : guess - 1;
	            break;
	        case 'l':
	            min = min > (guess + 1) ? min : guess + 1;
	            break;
	        case 't':
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
