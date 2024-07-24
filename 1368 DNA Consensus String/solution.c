#include <stdio.h>

int main() {
    int T;
	scanf("%d", &T);
	char nucleotides[5] = "ACGT";
	while(T--) {
		int m, n;
		scanf("%d %d", &m, &n);
		char DNA[m][n + 1];
		for(int i = 0; i < m; ++i)
			scanf("%s", DNA[i]);
		int dist = m * n;
		for(int i = 0; i < n; ++i) {
            int nucleotidesCount[4] = {};
            for(int j = 0; j < m; ++j) {
                switch(DNA[j][i]) {
                    case 'A':
                        ++nucleotidesCount[0];
                        break;
                    case 'C':
                        ++nucleotidesCount[1];
                        break;
                    case 'G':
                        ++nucleotidesCount[2];
                        break;
                    case 'T':
                        ++nucleotidesCount[3];
                }
            }
            int max = 0, temp = -1;
            for(int j = 0; j < 4; ++j) {
                if(max < nucleotidesCount[j]) {
                    max = nucleotidesCount[j];
                    temp = j;
                }
            }
            putchar(nucleotides[temp]);
            dist -= max;
        }
        printf("\n%d\n", dist);
	}
	return 0;
}
