#include <stdio.h>

int main() {
    char ch, keyboard[] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    while((ch = getchar()) != EOF) {
    	if(ch == ' ' || ch == '\n')
    		putchar(ch);
    	else {
    		int i = 0;
    		while(ch != keyboard[i])
    			++i;
    		putchar(keyboard[i - 1]);
    	}
    }
    return 0;
}
