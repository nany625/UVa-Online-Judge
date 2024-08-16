#include <stdio.h>
#include <string.h>

int main() {
    char bed[500001];
    while(scanf("%s", bed) == 1) {
        int len = strlen(bed), prev = 0;
        while(prev < len && bed[prev] != 'X')
            ++prev;
        int curr = prev + 1, max = prev - 1;
        while(curr < len) {
            if(bed[curr] == 'X') {
                max = max > (curr - prev - 2) / 2 ? max : (curr - prev - 2) / 2;
                prev = curr;
            }
            ++curr;
        }
        max = max > (len - prev - 2) ? max : (len - prev - 2);
        printf("%d\n", max);
    }
    return 0;
}
