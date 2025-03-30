#include <stdio.h>

int tokenSum(char *number, int first, int last) {
	int result = 0;
    for(int i = first; i < last; ++i) {
        int digit = number[i] - '0';
	    if(i % 5 & 1)
            result += digit;
	    else
	        result += (digit << 1) / 10 + (digit << 1) % 10;
    }
    return result;
}
	
int main() {
	int N;
	scanf("%d ", &N);
	char number[21];
	while(N--) {
	    fgets(number, sizeof(number), stdin);
	    puts((tokenSum(number, 0, 4) + tokenSum(number, 5, 9) + tokenSum(number, 10, 14) + tokenSum(number, 15, 19)) % 10 == 0 ? "Valid" : "Invalid");
	}
	return 0;
}
