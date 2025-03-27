#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define MAXN 50000

int sent[MAXN + 1];
bool visited1[MAXN + 1], visited2[MAXN + 1];

void dfs(int start, int *count) {
	visited1[start] = visited2[start] = true;
	++(*count);
	if(!visited2[sent[start]])
		dfs(sent[start], count);
}

int main() {
	int T;
	scanf("%d", &T);
	for(int i = 1; i <= T; ++i) {
		int N;
		scanf("%d", &N);
		for(int j = 0; j < N; ++j) {
			int u, v;
			scanf("%d %d", &u, &v);
			sent[u] = v;
		}
		memset(visited1, 0, sizeof(visited1));
		int m = 0, max = 0;
		for(int j = 1; j <= N; ++j) {
			if(!visited1[j]) {
				memset(visited2, 0, sizeof(visited2));
				int count = 0;
				dfs(j, &count);
				if(max < count) {
					m = j;
					max = count;
				}
			}
		}
		printf("Case %d: %d\n", i, m);
	}
	return 0;
}
