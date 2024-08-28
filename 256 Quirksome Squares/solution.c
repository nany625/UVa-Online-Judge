// #解法一(正規演算法)
#include <stdio.h>
#include <math.h>

int main() {
	int n;
	while(scanf("%d", &n) == 1) {
		for(int i = 0; i < pow(10, n >> 1); ++i) {
        	int split1 = i * i / (int)pow(10, n >> 1);
        	int split2 = i * i % (int)pow(10, n >> 1);
        	if(i * i == (split1 + split2) * (split1 + split2))
        		printf("%0*d\n", n, i * i);
       	}
	}
	return 0;
}

// #解法二(捷徑)
#include <stdio.h>

int main() {
	int n;
	while(scanf("%d", &n) == 1) {
		if(n == 2)
			puts("00\n01\n81");
		else if(n == 4)
			puts("0000\n0001\n2025\n3025\n9801");
		else if(n == 6)
			puts("000000\n000001\n088209\n494209\n998001");
		else if(n == 8)
			puts("00000000\n00000001\n04941729\n07441984\n24502500\n25502500\n52881984\n60481729\n99980001");
	}
	return 0;
}
