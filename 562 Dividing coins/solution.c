#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

int main() {
    int n;
    scanf("%d", &n);
    char *buffer = NULL;
    size_t bufsize = 0;
    while(n--) {
        int m;
        scanf("%d", &m);
        getchar();
        getline(&buffer, &bufsize, stdin);
        char *token = strtok(buffer, " ");
        int coins[m], sum = 0;
        for(int i = 0; i < m; ++i) {
            sum += coins[i] = atoi(token);
            token = strtok(NULL, " ");
        }
        int temp = sum / 2, max = 0;
        bool subsetSum[temp + 1];
        subsetSum[0] = true;
        memset(subsetSum + 1, 0, temp * sizeof(bool));
        for(int i = 0; i < m && max < temp; ++i) {
            for(int j = temp; j >= coins[i] && max < temp; --j) {
                if(subsetSum[j] |= subsetSum[j - coins[i]])
                    max = max > j ? max : j;
            }
        }
        printf("%d\n", sum - 2 * max);
    }
    free(buffer);
	return 0;
}
