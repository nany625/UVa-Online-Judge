#include <stdio.h>
#include <string.h>

int main() {
	int T;
	scanf("%d", &T);
    char N[1001];
	for(int i = 1; i <= T; ++i) {
		scanf("%s", N);
		int len = strlen(N);
		short modThreeCount[3] = {};
		for(int j = 0; j < len; ++j)
			++modThreeCount[(N[j] - '0') % 3];
		short result = (modThreeCount[1] + (modThreeCount[2] << 1)) % 3;
		if(result == 0)
			printf("Case %d: %c\n", i, modThreeCount[0] & 1 ? 'S' : 'T');
		else
			printf("Case %d: %c\n", i, modThreeCount[result] && !(modThreeCount[0] & 1) ? 'S' : 'T');
	}
	return 0;
}
