#include <stdio.h>
#include <stdlib.h>

int main() {
    int *numbers = NULL, size = 0, X;
    while(scanf("%d", &X) == 1) {
        numbers = (int*)realloc(numbers, (size + 1) * sizeof(int));
        int pos = size++;
        while(pos > 0 && X < numbers[pos - 1]) {
            numbers[pos] = numbers[pos - 1];
            --pos;
        }
        numbers[pos] = X;
        if(size & 1)
            printf("%d\n", numbers[size >> 1]);
        else
            printf("%d\n", numbers[(size >> 1) - 1] + ((numbers[size >> 1] - numbers[(size >> 1) - 1]) >> 1));
    }
    free(numbers);
	return 0;
}
