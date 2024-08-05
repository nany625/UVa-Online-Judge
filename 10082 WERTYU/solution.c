#include <stdio.h>

int main() {
    char ch, keyboard[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    char ASCII[128];
    for(int i = 1; i < 47; ++i) 
        ASCII[(int)keyboard[i]] = keyboard[i - 1];
    while((ch = getchar()) != EOF) {
    	if(ch == ' ' || ch == '\n')
    		putchar(ch);
    	else
    		putchar(ASCII[(int)ch]);
    }
    return 0;
}
