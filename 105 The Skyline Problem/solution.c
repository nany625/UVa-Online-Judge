// #解法一
#include <stdio.h>
#include <stdbool.h>

int main() {
	short skyline[10000] = {};
	int L, H, R, limit = 0;
	while(scanf("%d %d %d", &L, &H, &R) == 3) {
	    for(int i = L; i < R; ++i)
	        skyline[i] = skyline[i] > H ? skyline[i] : H;
	    limit = limit > R ? limit : R;
	}
	bool firstBuilding = true;
	for(int i = 1; i <= limit; ++i) {
	    if(skyline[i] != skyline[i - 1]) {
	        if(!firstBuilding)
	            putchar(' ');
	        printf("%d %hd", i, skyline[i]);
	        firstBuilding = false;
	    }
	}
    puts("");
	return 0;
}

// #解法二
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int compare(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int main() {
	int skyline[10000] = {}, *check = NULL, size = 0, L, H, R;
	bool isBuilding[10000] = {};
	while(scanf("%d %d %d", &L, &H, &R) == 3) {
	    if(skyline[L] < H && !isBuilding[L]) {
	        check = (int*)realloc(check, (size + 1) * sizeof(int));
    	    check[size++] = L;
    	    isBuilding[L] = true;
	    }
	    if(skyline[R] < H && !isBuilding[R]) {
	        check = (int*)realloc(check, (size + 1) * sizeof(int));
    	    check[size++] = R;
    	    isBuilding[R] = true;
	    }
	    for(int i = L; i < R; ++i)
	        skyline[i] = skyline[i] > H ? skyline[i] : H;
	}
	qsort(check, size, sizeof(int), compare);
	bool firstBuilding = true;
	for(int i = 0; i < size; ++i) {
	    if(skyline[check[i]] != skyline[check[i] - 1]) {
	        if(!firstBuilding)
	            putchar(' ');
	        printf("%d %d", check[i], skyline[check[i]]);
	        firstBuilding = false;
	    }
	}
	puts("");
	free(check);
	return 0;
}
