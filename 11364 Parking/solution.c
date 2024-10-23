#include <stdio.h>

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
	    int n;
	    scanf("%d", &n);
	    int position, min = 99, max = 0;
	    while(n--) {
	        scanf("%d", &position);
	        min = min < position ? min : position;
	        max = max > position ? max : position;
	    }
	    printf("%d\n", max - min << 1);
	}
	return 0;
}
