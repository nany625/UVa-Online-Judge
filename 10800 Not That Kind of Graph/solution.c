#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	int N;
	scanf("%d", &N);
	for(int i = 1; i <= N; ++i) {
		printf("Case #%d:\n", i);
		char *stockPrice = NULL;
		scanf("%ms", &stockPrice);
		int min, max, curr = 0;
		if(stockPrice[0] == 'R')
			min = max = curr++;
		else if(stockPrice[0] == 'F')
			min = max = --curr;
		else if(stockPrice[0] == 'C')
			min = max = curr;
		int len = strlen(stockPrice);
		for(int j = 1; j < len; ++j) {
			if(stockPrice[j] == 'R'){
				if(max < curr)
					max = curr;
				++curr;
			} else if(stockPrice[j] == 'F') {
				--curr;
				if(min > curr)
					min = curr;
			} else if(stockPrice[j] == 'C') {
				if(min > curr)
					min = curr;
				if(max < curr)
					max = curr;
			}
		}
		char graph[max - min + 1][len + 1];
		int start = max;
		for(int j = 0; j < len; ++j) {
			for(int k = 0; k < max - min + 1; ++k) {
				graph[k][j] = ' ';
				graph[k][j + 1] = '\0';
			}
			if(stockPrice[j] == 'R')
				graph[start--][j] = '/';
			else if(stockPrice[j] == 'F')
				graph[++start][j] = '\\';
			else if(stockPrice[j] == 'C')
				graph[start][j] = '_';
		}
		for(int j = 0; j < max - min + 1; ++j) {
		    len = strlen(graph[j]) - 1;
			while(graph[j][len] == ' ')
				graph[j][len--] = '\0';
			printf("| %s\n", graph[j]);
		}
		putchar('+');
		len = strlen(stockPrice) + 2;
		while(len--)
			putchar('-');
		puts("\n");
		free(stockPrice);
	}
	return 0;
}
