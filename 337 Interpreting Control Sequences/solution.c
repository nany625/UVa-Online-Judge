#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char screen[10][11];

void clear() {
	for(int i = 0; i < 10; ++i) {
	    memset(screen[i], ' ', 10);
	    screen[i][10] = '\0';
	}
}

void write(int row, int *col, char ch, bool override) {
    if(override)
	    screen[row][*col] = ch;
	else {
	    memmove(screen[row] + *col + 1, screen[row] + *col, 9 - *col);
	    screen[row][*col] = ch;
	}
	*col = *col < 9 ? *col + 1 : *col;
}

int main() {
	int cases = 0, N;
	while(scanf("%d", &N) && N != 0) {
	    printf("Case %d\n", ++cases);
	    getchar();
	    clear();
	    int cursorRow = 0, cursorCol = 0;
	    bool override = true;
	    while(N--) {
	        char data[33];
	        fgets(data, sizeof(data), stdin);
	        data[strcspn(data, "\n")] = '\0';
	        int len = strlen(data);
	        for(int i = 0; i < len; ++i) {
	            if(data[i] == '^') {
	                char control = data[++i];
	                if(control == 'b')
	                    cursorCol = 0;
	                else if(control == 'c')
	                    clear();
	                else if(control == 'd') {
	                    if(cursorRow < 9)
	                        ++cursorRow;
	                } else if(control == 'e')
	                    memset(screen[cursorRow] + cursorCol, ' ', 10 - cursorCol);
	                else if(control == 'h')
	                    cursorRow = cursorCol = 0;
	                else if(control == 'i')
	                    override = false;
	                else if(control == 'l') {
	                    if(cursorCol > 0)
	                        --cursorCol;
	                } else if(control == 'o')
	                    override = true;
	                else if(control == 'r') {
	                    if(cursorCol < 9)
	                        ++cursorCol;
	                } else if(control == 'u') {
	                    if(cursorRow > 0)
	                        --cursorRow;
	                } else if(isdigit(control)) {
	                    cursorRow = control - '0';
	                    cursorCol = data[++i] - '0';
	                } else
	                    write(cursorRow, &cursorCol, control, override);
	            } else
	                write(cursorRow, &cursorCol, data[i], override);
	        }
	    }
	    puts("+----------+");
	    for(int i = 0; i < 10; ++i)
	        printf("|%s|\n", screen[i]);
	    puts("+----------+");
	}
	return 0;
}
