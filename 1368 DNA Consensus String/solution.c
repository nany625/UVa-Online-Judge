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
                if(DNA[j][i] == 'A')
                    ++nucleotidesCount[0];
                else if(DNA[j][i] == 'C')
                    ++nucleotidesCount[1];
                else if(DNA[j][i] == 'G')
                    ++nucleotidesCount[2];
                else if(DNA[j][i] == 'T')
                    ++nucleotidesCount[3];
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
