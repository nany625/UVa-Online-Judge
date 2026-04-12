#include <stdio.h>
#include <stdlib.h>

short courses[5];

void InsertionSort() {
    for(int i = 1; i < 5; ++i) {
        int j = i - 1;
        short insertionNum = courses[i];
        while(j >= 0 && insertionNum < courses[j]) {
            courses[j + 1] = courses[j];
            --j;
        }
        courses[j + 1] = insertionNum;
    }
}

int compare(const void *a, const void *b) {
    return *(long*)a > *(long*)b;
}

int main() {
	int n;
	while(scanf("%d", &n) && n != 0) {
	    long combinations[n];
		for(int i = 0; i < n; ++i) {
		    for(int j = 0; j < 5; ++j)
		        scanf("%hd", &courses[j]);
		    InsertionSort();
		    combinations[i] = 0;
		    for(int j = 0; j < 5; ++j)
		        combinations[i] = 1000 * combinations[i] + courses[j];
		}
		qsort(combinations, n, sizeof(long), compare);
		int max = 1, students = 0, count = 1;
		for(int i = 1; i < n; ++i) {
		    if(combinations[i] == combinations[i - 1])
		        ++count;
		    else {
		        if(max < count)
    		        students = max = count;
    		    else if(max == count)
    		        students += max;
    		    count = 1;
		    }
		}
		if(max < count)
        	students = max = count;
        else if(max == count)
            students += max;
		printf("%d\n", students);
	}
	return 0;
}
