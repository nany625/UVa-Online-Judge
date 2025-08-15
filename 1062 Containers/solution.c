#include <stdio.h>
#include <string.h>

int binarySearch(char *array, int size, char key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left >> 1);
        if(array[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left;
}

int main() {
    int cases = 0;
    char container[1001], lis[27];
    while(scanf("%s", container) && container[0] != 'e') {
        int len = strlen(container), size = 0;
        for(int i = 0; i < len; ++i) {
            int pos = binarySearch(lis, size, container[i]);
            lis[pos] = container[i];
            if(pos == size)
                ++size;
        }
        printf("Case %d: %d\n", ++cases, size);
    }
    return 0;
}
