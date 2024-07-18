#include <stdio.h>

int main() {
	int H1, M1, H2, M2;
	while(scanf("%d %d %d %d", &H1, &M1, &H2, &M2) && (H1 != 0 || M1 != 0 || H2 != 0 || M2 != 0)) {
	    int time1 = 60 * H1 + M1, time2 = 60 * H2 + M2;
	    printf("%d\n", time1 <= time2 ? time2 - time1 : time2 - time1 + 1440);
	}
	return 0;
}
