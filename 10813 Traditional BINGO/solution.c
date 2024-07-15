#include <stdio.h>
#include <stdbool.h>

typedef struct {
    short num;
    bool announce;
} Card;

Card bingo[5][5];

bool isBINGO(int row, int col) {
    bool found = true;
    for(int i = 0; i < 5 && found; ++i)
        found = bingo[row][i].announce;
    if(found)
        return true;
    found = true;
    for(int i = 0; i < 5 && found; ++i)
        found = bingo[i][col].announce;
    if(found)
        return true;
    if(row == col || row + col == 4) {
        found = true;
        for(int i = 0; i < 5 && found; ++i)
            found = bingo[i][i].announce;
        if(found)
            return true;
        found = true;
        for(int i = 0; i < 5 && found; ++i)
            found = bingo[i][4 - i].announce;
        if(found)
            return true;
    }
    return false;
}

int main() {
    
    int n;
    scanf("%d", &n);
    while(n--) {
        for(int i = 0; i < 5; ++i) {
			for(int j = 0; j < 5; ++j) {
				if(i == 2 && j == 2) {
				    bingo[i][j].announce = true;
					continue;
				}
				scanf("%hd", &bingo[i][j].num);
				bingo[i][j].announce = false;
			}
		}
		short order;
		bool win = false;
		for(int i = 1; i <= 75; ++i) {
		    scanf("%hd", &order);
		    if(!win) {
		        int col = (order - 1) / 15, row = 0;
    		    while(row < 5 && bingo[row][col].num != order) 
    		        ++row;
    		    if(row < 5) {
    		        bingo[row][col].announce = true;
    		        if(i >= 4)
    		            win = isBINGO(row, col);
    		    }
    		    if(win)
    		        printf("BINGO after %d numbers announced\n", i);
		    }
		}
    }
    return 0;
}
