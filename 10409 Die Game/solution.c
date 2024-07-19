#include <stdio.h>

int main() {
    char command[6];
    int n;
    while(scanf("%d", &n) && n != 0) {
        char top = '1', north = '2', west = '3', east = '4', south = '5', bottom = '6';
        while(n--) {
            scanf("%s", command);
            char temp = top;
            switch(command[0]) {
                case 'n':
                    top = south;
                    south = bottom;
                    bottom = north;
                    north = temp;
                    break;
                case 'e':
                    top = west;
                    west = bottom;
                    bottom = east;
                    east = temp;
                    break;
                case 's':
                    top = north;
                    north = bottom;
                    bottom = south;
                    south = temp;
                    break;
                case 'w':
                    top = east;
                    east = bottom;
                    bottom = west;
                    west = temp;
            }
        }
        printf("%c\n", top);
    }
    return 0;
}
