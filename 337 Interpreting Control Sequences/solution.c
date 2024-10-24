#include <stdio.h>
#include <stdlib.h>
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
	*col += *col < 9;
}

int main() {
	int cases = 0, N;
	char *buffer = NULL;
	size_t bufsize = 0;
	while(scanf("%d", &N) && N != 0) {
	    printf("Case %d\n", ++cases);
	    getchar();
	    clear();
	    int cursorRow = 0, cursorCol = 0;
	    bool override = true;
	    while(N--) {
	        getline(&buffer, &bufsize, stdin);
	        buffer[strcspn(buffer, "\n")] = '\0';
	        int len = strlen(buffer);
	        for(int i = 0; i < len; ++i) {
	            if(buffer[i] == '^') {
	                char control = buffer[++i];
	                if(control == 'b')
	                    cursorCol = 0;
	                else if(control == 'c')
	                    clear();
	                else if(control == 'd')
	                    cursorRow += cursorRow < 9;
	                else if(control == 'e')
	                    memset(screen[cursorRow] + cursorCol, ' ', 10 - cursorCol);
	                else if(control == 'h')
	                    cursorRow = cursorCol = 0;
	                else if(control == 'i')
	                    override = false;
	                else if(control == 'l')
	                    cursorCol -= cursorCol > 0;
	                else if(control == 'o')
	                    override = true;
	                else if(control == 'r')
	                    cursorCol += cursorCol < 9;
	                else if(control == 'u')
	                    cursorRow -= cursorRow > 0;
	                else if(isdigit(control)) {
	                    cursorRow = control - '0';
	                    cursorCol = buffer[++i] - '0';
	                } else
	                    write(cursorRow, &cursorCol, control, override);
	            } else
	                write(cursorRow, &cursorCol, buffer[i], override);
	        }
	    }
	    puts("+----------+");
	    for(int i = 0; i < 10; ++i)
	        printf("|%s|\n", screen[i]);
	    puts("+----------+");
	}
	free(buffer);
	return 0;
}
