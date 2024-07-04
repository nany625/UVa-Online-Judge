#include <stdio.h>
#include <string.h>

long factorials[] = {
    1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800, 
    39916800, 479001600, 6227020800, 87178291200, 1307674368000, 20922789888000, 355687428096000, 6402373705728000, 121645100408832000
};

void InsertionSort(char *array) {
    int size = strlen(array);
    for(int i = 1; i < size; ++i) {
        int j = i - 1, insertionChar = array[i];
        while(j >= 0 && insertionChar < array[j]) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = insertionChar;
    }
}

int main() {
	int samples;
	scanf("%d", &samples);
	while(samples--) {
		char S[21];
		long N;
		scanf("%s %ld", S, &N);
		InsertionSort(S);
		int len = strlen(S);
		for(int i = len - 2; i >= 0; --i) {
			int index = N / factorials[i];
			putchar(S[index]);
			memmove(S + index, S + index + 1, len-- - index - 1);
			N %= factorials[i];
		}
		printf("%c\n", S[0]);
	}
	return 0;
}
