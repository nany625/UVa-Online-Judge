#include <stdio.h>
#include <string.h>

int binarySearch(int *array, int size, int key) {
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
    int a, c, m, x, q, n;
    while(scanf("%d %d %d %d %d %d", &a, &c, &m, &x, &q, &n) == 6) {
        int indices[2][m];
        memset(indices, 0, sizeof(indices));
        int pos = 0;
        do {
            indices[0][x] = ++pos;
            x = (a * x + c) % m;
        } while(indices[0][x] == 0);
        int temp = indices[0][x] - 1, cycle = pos - temp;
        n -= temp;
        for(int i = 0, j = 0; j < pos; ++i) {
            if(indices[0][i] == 0)
                continue;
            if(indices[0][i] <= temp)
                indices[1][j] = 1;
            else
                indices[1][j] = n / cycle + (indices[0][i] - temp - 1 < n % cycle);
            indices[0][j++] = i;
        }
        for(int i = 1; i < pos; ++i)
            indices[1][i] += indices[1][i - 1];
        while(q--) {
            int query;
            scanf("%d", &query);
            printf("%d\n", indices[0][binarySearch(indices[1], pos, query)]);
        }
    }
	return 0;
}
