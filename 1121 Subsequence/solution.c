#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXN 99999

int sequence[MAXN];

int main() {
	int N, S;
	char *buffer = NULL;
	size_t bufsize = 0;
	while(scanf("%d %d ", &N, &S) == 2) {
	    getline(&buffer, &bufsize, stdin);
	    char *token = strtok(buffer, " ");
	    int start = 0, ans = N, sum = 0;
	    for(int i = 0; i < N; ++i) {
	        sequence[i] = atoi(token);
	        sum += sequence[i];
	        if(sum >= S) {
	            while(start < N && sum - sequence[start] >= S)
	                sum -= sequence[start++];
	            ans = ans < i - start + 1 ? ans : i - start + 1;
	            sum -= sequence[start++];
	        }
	        token = strtok(NULL, " ");
	    }
	    printf("%d\n", ans == N ? 0 : ans);
	}
	free(buffer);
	return 0;
}
