#include <stdio.h>

int main() {
    int N;
    while(scanf("%d", &N) && N != 0) {
        short array[N];
        for(int i = 0; i < N; ++i) {
            scanf("%hd", &array[i]);
            if(array[i] == 0) {
                --i;
                --N;
            }
        }
        int max = array[0], curr = array[0], start = 0, first = 0, last = 0, length = 1;
        for(int i = 1; i < N; ++i) {
            if(array[i] > curr + array[i]) {
                curr = array[i];
                first = i;
            } else {
                curr += array[i];
                last = i;
            }
            if(max < curr) {
                max = curr;
                length = last - (start = first) + 1;
            }
        }
        if(N == 0)
            puts("0");
        else {
            for(int i = start; i < start + length; ++i) {
                if(i > start)
                    putchar(' ');
                printf("%d", array[i]);
            }
            putchar('\n');
        }
    }
	return 0;
}
