#include <stdio.h>
#include <stdlib.h>

int main() {
	char number[8], digits[8] = {};
	int baseFrom, baseTo;
	while(scanf("%s %d %d", number, &baseFrom, &baseTo) == 3) {
		int num = strtol(number, NULL, baseFrom);
		if(num == 0) {
		    puts("      0");
		    continue;
	    }
		for(int i = 6; i >= 0; --i) {
		    int digit = num % baseTo;
			digits[i] = digit > 9 ? digit - 10 + 'A' : digit + '0';
			num /= baseTo;
		}
		if(num > 0)
			puts("  ERROR");
		else {
			int i = -1;
			while(digits[++i] == '0')
			    putchar(' ');
			puts(digits + i);
		}
	}
	return 0;
}
