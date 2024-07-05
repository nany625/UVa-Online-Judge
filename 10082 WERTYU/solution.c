#include <stdio.h>
#include <string.h>

int main() {
    char text[100], keyboard[]="`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
    while(fgets(text, sizeof(text), stdin)) {
        int len = strlen(text);
    	for(int i = 0; i < len; ++i) {
    		if(text[i] == ' ' || text[i] == '\n')
    			putchar(text[i]);
    		else {
    			int j=0;
    			while(text[i] != keyboard[j])
    				++j;
    			putchar(keyboard[j-1]);
    		}
    	}
    }
    return 0;
}
