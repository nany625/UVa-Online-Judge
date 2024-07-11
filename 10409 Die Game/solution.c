#include <stdio.h>
#include <string.h>

int main() {
    int n;
    while(scanf("%d", &n) && n != 0) {
        char command[6], top = '1', north = '2', west = '3', east = '4', south = '5', bottom = '6';
        while(n--) {
            scanf("%s", command);
            char temp = top;
            if(strcmp(command, "north") == 0) {
                top = south;
                south = bottom;
                bottom = north;
                north = temp;
            } else if(strcmp(command, "east") == 0) {
                top = west;
                west = bottom;
                bottom = east;
                east = temp;
            } else if(strcmp(command, "south") == 0) {
                top = north;
                north = bottom;
                bottom = south;
                south = temp;
            } else if(strcmp(command, "west") == 0) {
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
