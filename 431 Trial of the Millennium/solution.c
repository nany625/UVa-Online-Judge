#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

typedef struct {
    int score, time;
    char description[100];
} Evidence;

int compare(const void *a, const void *b) {
    Evidence *e1 = (Evidence*)a;
    Evidence *e2 = (Evidence*)b;
    if(e1->time == e2->time)
        return e1->score > e2->score;
    return e1->time < e2->time;
}

int main() {
    int cases;
    scanf("%d", &cases);
    char *buffer;
    size_t bufsize = 0;
    while(cases--) {
        int totalTime;
        scanf("%d", &totalTime);
        getline(&buffer, &bufsize, stdin);
        Evidence *evidences = NULL;
        int size = 0;
        while(getline(&buffer, &bufsize, stdin) != -1) {
            buffer[strcspn(buffer, "\n")] = '\0';
            int i = 0, len = strlen(buffer);
            while(i < len && buffer[i] == ' ')
                ++i;
            if(i == len)
                break;
            char *token = strtok(buffer, " ");
            evidences = (Evidence*)realloc(evidences, (size + 1) * sizeof(Evidence));
            evidences[size].score = atoi(token);
            token = strtok(NULL, " ");
            evidences[size].time = atoi(token);
            int count = 0;
            while(count < 2) {
                if(isdigit(buffer[i])) {
                    ++count;
                    while(isdigit(buffer[i]))
                        ++i;
                }
                ++i;
            }
            while(buffer[i] == ' ')
                ++i;
            strcpy(evidences[size++].description, buffer + i);
        }
        qsort(evidences, size, sizeof(Evidence), compare);
        int dp[totalTime + 1];
        memset(dp, 0, sizeof(dp));
        bool selected[size][totalTime + 1];
        memset(selected, 0, sizeof(selected));
        for(int i = 0; i < size; ++i) {
            int s = evidences[i].score;
            int t = evidences[i].time;
            for(int j = totalTime; j >= t; --j) {
                if(dp[j] < dp[j - t] + s) {
                    dp[j] = dp[j - t] + s;
                    selected[i][j] = true;
                }
            }
        }
        int currentTime = totalTime, totalScore = 0;
        totalTime = 0;
        bool drop = true;
        for(int i = size - 1; i >= 0; --i) {
            if(selected[i][currentTime]) {
                if(drop) {
                    puts("Score  Time  Description\n-----  ----  -----------");
                    drop = false;
                }
                printf("%3d    %3d   %s\n", evidences[i].score, evidences[i].time, evidences[i].description);
                totalScore += evidences[i].score;
                totalTime += evidences[i].time;
                currentTime -= evidences[i].time;
            }
        }
        if(drop)
            puts("There is not enough time to present any evidence. Drop the charges.");
        else
            printf("\nTotal score: %d points\n Total time: %d hours\n", totalScore, totalTime);
        if(cases)
            putchar('\n');
        free(evidences);
    }
    free(buffer);
    return 0;
}
