#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void InsertionSort(int *array, int size) {
    for(int i = 1; i < size; ++i) {
        int j = i - 1, insertionNum = array[i];
        while(j >= 0 && insertionNum < array[j]) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = insertionNum;
    }
}

int main() {
	char encryption[101], origin[101];
	while(scanf("%s %s", encryption, origin) == 2) {
	    int frequency[2][26] = {}, len = strlen(encryption);
	    for(int i = 0; i < len; ++i) {
	        ++frequency[0][encryption[i] - 'A'];
			++frequency[1][origin[i] - 'A'];
	    }
	    InsertionSort(frequency[0], 26);
	    InsertionSort(frequency[1], 26);
	    int i = 25;
	    while(i >= 0 && frequency[0][i] == frequency[1][i] && frequency[0][i] > 0)
	        --i;
	    puts(i < 0 || frequency[0][i] == frequency[1][i] ? "YES" : "NO");
	}
	return 0;
}
