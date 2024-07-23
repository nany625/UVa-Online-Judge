#include <stdio.h>
#include <stdlib.h>

int main() {
    int prevHour = 0, prevMinute = 0, prevSecond = 0, prevSpeed = 0;
    int currHour, currMinute, currSecond, currSpeed;
    float dist = 0;
    char *buffer = NULL;
    size_t bufsize = 0;
    while(getline(&buffer, &bufsize, stdin) != -1) {
        int len = sscanf(buffer, "%d %*c %d %*c %d %d", &currHour, &currMinute, &currSecond, &currSpeed);
        dist += (3600 * (currHour - prevHour) + 60 * (currMinute - prevMinute) + (currSecond - prevSecond)) / 3600.0 * prevSpeed;
        if(len == 3)
            printf("%02d:%02d:%02d %.2f km\n", currHour, currMinute, currSecond, dist);
        else if(len == 4)
            prevSpeed = currSpeed;
        prevHour = currHour;
        prevMinute = currMinute;
        prevSecond = currSecond;
    }
    free(buffer);
    return 0;
}
