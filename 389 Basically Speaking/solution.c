#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>

int main() {
	char number[8];
	int digits[7], baseFrom, baseTo;
	while(scanf("%s %d %d", number, &baseFrom, &baseTo) == 3) {
		int num = 0, len = strlen(number);
		for(int i = 0; i < len; ++i) {
			if(isupper(number[i]))
			    num += (number[i] - 'A' + 10) * pow(baseFrom, len - 1 - i);
			else
		        num += (number[i] - '0') * pow(baseFrom, len - 1 - i);
		}
		if(num == 0) {
		    puts("      0");
		    continue;
	    }
		for(int i = 6; i >= 0; --i) {
			digits[i] = num % baseTo;
			num /= baseTo;
		}
		if(num > 0)
			puts("  ERROR");
		else {
			bool leadingZero = true;
			for(int i = 0; i < 7; ++i) {
				if(digits[i] == 0 && leadingZero)
					putchar(' ');
				else {
					leadingZero = false;
					if(digits[i] > 9)
						putchar(digits[i] - 10 + 'A');
					else
						printf("%d", digits[i]);
				}
			}
			puts("");
		}
	}
	return 0;
}
