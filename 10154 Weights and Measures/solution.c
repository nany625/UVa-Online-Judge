// #解法一
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight, strength;
} Turtle;

int compare(const void *a, const void *b) {
    return ((Turtle*)a)->strength > ((Turtle*)b)->strength;
}

int main() {
    Turtle *turtles = NULL;
    int size = 0, w, s;
    while(scanf("%d %d", &w, &s) == 2) {
        turtles = (Turtle*)realloc(turtles, (size + 1) * sizeof(Turtle));
        turtles[size++] = (Turtle){w, s};
    }
    qsort(turtles, size, sizeof(Turtle), compare);
    int *stacked = NULL, totalWeight = 0, height = 0;
    for(int i = 0; i < size; ++i) {
        if(totalWeight + turtles[i].weight <= turtles[i].strength) {
            stacked = (int*)realloc(stacked, (height + 1) * sizeof(int));
            totalWeight += stacked[height++] = turtles[i].weight;
        } else if(height > 0) {
            int maxIndex = 0;
            for(int j = 1; j < height; ++j) {
                if(stacked[j] > stacked[maxIndex])
                    maxIndex = j;
            }
            if(stacked[maxIndex] > turtles[i].weight) {
                totalWeight += turtles[i].weight - stacked[maxIndex];
                stacked[maxIndex] = turtles[i].weight;
            }
        }
    }
    printf("%d\n", height);
    free(stacked);
    free(turtles);
	return 0;
}

// #解法二
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int weight, strength;
} Turtle;

int compare(const void *a, const void *b) {
    return ((Turtle*)a)->strength > ((Turtle*)b)->strength;
}

int main() {
    Turtle *turtles = NULL;
    int size = 0, w, s;
    while(scanf("%d %d", &w, &s) == 2) {
        turtles = (Turtle*)realloc(turtles, (size + 1) * sizeof(Turtle));
        turtles[size++] = (Turtle){w, s};
    }
    qsort(turtles, size, sizeof(Turtle), compare);
    int dp[size + 1], maxHeight = 0;
    dp[0] = 0;
    for(int i = 0; i < size; ++i) {
        dp[i + 1] = 1e9;
        for(int j = maxHeight; j >= 0; --j) {
            if(dp[j] + turtles[i].weight <= turtles[i].strength) {
                dp[j + 1] = dp[j + 1] < dp[j] + turtles[i].weight ? dp[j + 1] : dp[j] + turtles[i].weight;
                maxHeight = maxHeight > j + 1 ? maxHeight : j + 1;
            }
        }
    }
    printf("%d\n", maxHeight);
    free(turtles);
	return 0;
}
