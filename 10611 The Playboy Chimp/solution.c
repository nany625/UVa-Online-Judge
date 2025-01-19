#include <stdio.h>

int ans[2];

void binarySearch(int *array, int size, int key) {
    int left = 0, right = size - 1;
    while(left <= right) {
        int mid = left + (right - left >> 1);
        if(array[mid] == key) {
            left = mid - 1;
            while(left >= 0 && array[left] == key)
                --left;
            ans[0] = left == -1 ? -1 : array[left];
            right = mid + 1;
            while(right < size && array[right] == key)
                ++right;
            ans[1] = right == size ? -1 : array[right];
            return;
        }
        if(array[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    ans[0] = left == 0 ? -1 : array[left - 1];
    ans[1] = left == size ? -1 : array[left];
}

int main() {
    int N;
    scanf("%d", &N);
    int heights[N];
    for(int i = 0; i < N; ++i)
        scanf("%d", &heights[i]);
    int Q;
    scanf("%d", &Q);
    while(Q--) {
        int height;
        scanf("%d", &height);
        binarySearch(heights, N, height);
        if(ans[0] == -1)
            putchar('X');
        else
            printf("%d", ans[0]);
        if(ans[1] == -1)
            puts(" X");
        else
            printf(" %d\n", ans[1]);
    }
	return 0;
}
