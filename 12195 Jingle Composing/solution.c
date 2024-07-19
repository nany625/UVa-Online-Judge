#include <stdio.h>
#include <string.h>

int main() {
    char composition[202];
	while(fgets(composition, sizeof(composition), stdin) && composition[0] != '*') {
		int count = 0, duration = 0, len = strlen(composition) - 1;
		for(int i = 1; i < len; ++i) {
		    switch(composition[i]) {
			    case 'W':
				    duration += 64;
				    break;
    			case 'H':
    				duration += 32;
    				break;
    			case 'Q':
    				duration += 16;
    				break;
    			case 'E':
    				duration += 8;
    				break;
    			case 'S':
    				duration += 4;
    				break;
    			case 'T':
    				duration += 2;
    				break;
    			case 'X':
    				duration += 1;
    				break;
    			case '/':
    				count += duration == 64;
    				duration = 0;
		    }
		}
		printf("%d\n",count);
	}

    return 0;
}
