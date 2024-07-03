#include <stdio.h>
#include <stdbool.h>

int main() {
	short a;
	while(scanf("%hd", &a) && a != 0) {
		bool table[10000] = {};
		int count = 0;
		do {
		    table[a] = true;
		    ++count;
		    a = a * a / 100 % 10000;
		} while(!table[a]);
		printf("%d\n", count);
	}
}
