#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
	char R[945];
	while(scanf("%s", R) == 1) {
		int max = 1, sumOfDigits = 0, len = strlen(R);
		for(int i = 0; i < len; ++i) {
			int digit;
			if(isdigit(R[i]))
				digit = R[i] - '0';
			else if(isupper(R[i]))
				digit = R[i] - 'A' + 10;
			else if(islower(R[i]))
				digit = R[i] - 'a' + 36;
			sumOfDigits += digit;
			max = max > digit ? max : digit;
		}
		int N = max + 1;
		while(N <= 62 && sumOfDigits % (N - 1) != 0)
		    ++N;
		if(N <= 62)
		    printf("%d\n", N);
		else
			puts("such number is impossible!");
	}
	return 0;
}
