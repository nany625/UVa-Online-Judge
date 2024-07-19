#include <stdio.h>

int main() {
	int N;
	scanf("%d", &N);
	getchar();
	char number[21];
	while(N--) {
	    fgets(number, sizeof(number), stdin);
	    int sum = 0;
    	for(int i = 0; i < 19; ++i) {
    	    if((i - 4) % 5 == 0)
    	        continue;
            int digit = number[i] - '0';
	        if(i % 5 % 4 == 0 || i % 5 % 4 == 2)
	            sum += (2 * digit) / 10 + (2 * digit) % 10;
	        else
	            sum += digit;
	    }
	    puts(sum % 10 == 0 ? "Valid" : "Invalid");
	}
	return 0;
}
