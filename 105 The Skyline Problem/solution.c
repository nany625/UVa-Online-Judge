#include <stdio.h>
#include <stdbool.h>

int main() {
	int skyline[10000] = {}, L, H, R, limit = 0;
	while(scanf("%d %d %d", &L, &H, &R) == 3) {
	    for(int i = L; i < R; ++i)
	        skyline[i] = skyline[i] > H ? skyline[i] : H;
	    limit = limit > R ? limit : R;
	}
	bool firstBuilding = true;
	for(int i = 1; i < limit; ++i) {
	    if(skyline[i] != skyline[i - 1]) {
	        if(!firstBuilding)
	            putchar(' ');
	        printf("%d %d", i, skyline[i]);
	        firstBuilding = false;
	    }
	}
	if(!firstBuilding)
	    putchar(' ');
	printf("%d 0\n", limit);
	return 0;
}
