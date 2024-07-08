#include <stdio.h>

int main() {
    char buffer[13];
    int prevHour = 0, prevMinute = 0, prevSecond = 0, prevSpeed = 0;
    int currHour, currMinute, currSecond, currSpeed;
    float dist = 0;
    while(fgets(buffer, sizeof(buffer), stdin)) {
        int len = sscanf(buffer, "%d %*c %d %*c %d %d", &currHour, &currMinute, &currSecond, &currSpeed);
        dist += (3600 * (currHour - prevHour) + 60 * (currMinute - prevMinute) + (currSecond - prevSecond)) / 3600.0 * prevSpeed;
        if(len == 3)
            printf("%.2d:%.2d:%.2d %.2f km\n", currHour, currMinute, currSecond, dist);
        else if(len == 4)
            prevSpeed = currSpeed;
        prevHour = currHour;
        prevMinute = currMinute;
        prevSecond = currSecond;
    }
    return 0;
}
