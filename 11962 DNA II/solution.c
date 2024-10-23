#include <stdio.h>
#include <string.h>

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
                    B += (long)1 << (A - 1 - j << 1);
                    break;
                case 'G':
                    B += (long)1 << ((A - 1 - j << 1) + 1);
                    break;
                case 'T':
                    B += 3 * (long)1 << (A - 1 - j << 1);
            }
        }
        printf("Case %d: (%d:%ld)\n", i, A, B);
    }
	return 0;
}
