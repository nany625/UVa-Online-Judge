#include <stdio.h>

int main() {
	char ch;
	while((ch = getchar()) != EOF)
		putchar(ch == '\n' ? '\n' : ch - 7);
	return 0;
}
