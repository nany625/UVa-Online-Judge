#include <stdio.h>

int main() {
    char ASCII[128], keyboard[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    for(int i = 1; i < 47; ++i) 
        ASCII[(int)keyboard[i]] = keyboard[i - 1];
    char ch;
    while((ch = getchar()) != EOF) {
    	if(ch == ' ' || ch == '\n')
    		putchar(ch);
    	else
    		putchar(ASCII[(int)ch]);
    }
    return 0;
}
