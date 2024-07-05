#include <stdio.h>

int main() {
	int num1, num2;
	while(scanf("%d %d", &num1, &num2) &&  (num1 != 0 || num2 != 0)) {
	    int count = 0, carry = 0;
	    while((num1 > 0) + (num2 > 0) + (carry > 0) >= 2) {
	        carry = (num1 % 10 + num2 % 10 + carry) / 10;
	        count += carry;
	        num1 /= 10;
	        num2 /= 10;
	    }
	    if(count == 0)
	        puts("No carry operation.");
	    else
	        printf("%d carry operation%s", count, count > 1 ? "s.\n" : ".\n");
	}
	return 0;
}
