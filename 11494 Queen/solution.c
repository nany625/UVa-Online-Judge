#include <stdio.h>
#include <stdlib.h>

int main() {
    char buffer[9];
    while(fgets(buffer, sizeof(buffer), stdin) && buffer[0] != '0') {
        if(buffer[0] == buffer[4] && buffer[2] == buffer[6])
            puts("0");
        else if(buffer[0] == buffer[4] || buffer[2] == buffer[6] || abs(buffer[4] - buffer[0]) == abs(buffer[6] - buffer[2]))
            puts("1");
        else
            puts("2");
    }
	return 0;
}
