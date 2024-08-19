#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
    int T;
    scanf("%d", &T);
    char DNA[31];
    for(int i = 1; i <= T; ++i) {
        scanf("%s", DNA);
        int A = strlen(DNA);
        long B = 0;
        for(int j = 0; j < A; ++j) {
            switch(DNA[j]) {
                case 'C':
                    B += (long)pow(4, A - 1 - j);
                    break;
                case 'G':
                    B += 2 * (long)pow(4, A - 1 - j);
                    break;
                case 'T':
                    B += 3 * (long)pow(4, A - 1 - j);
            }
        }
        printf("Case %d: (%d:%ld)\n", i, A, B);
    }
	return 0;
}
