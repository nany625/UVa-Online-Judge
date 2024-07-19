// #解法一
#include <stdio.h>

int main() {
    int a, b, c, d, L;
	while(scanf("%d %d %d %d %d", &a, &b, &c, &d, &L) && (a != 0 || b != 0 || c != 0 || d != 0 || L != 0)) {
	    int count = 0, limit = d - 1 < L ? d - 1 : L;
	    for(int x = 0; x <= limit; ++x) {
	        if((a * x * x + b * x + c) % d == 0)
	            count += (L - x) / d + 1;
	    }
	    printf("%d\n", count);
	}
    return 0;
}

// #解法二
#include <stdio.h>

int main() {
    int a, b, c, d, L;
	while(scanf("%d %d %d %d %d", &a, &b, &c, &d, &L) && (a != 0 || b != 0 || c != 0 || d != 0 || L != 0)) {
	    int count = 0;
	    for(int x = 0; x <= L; ++x)
	        count += (a * x * x + b * x + c) % d == 0;
	    printf("%d\n", count);
	}
    return 0;
}
