#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    double PI = acos(-1);
    int N;
    scanf("%d", &N);
    getchar();
    char *buffer = NULL;
    size_t bufsize = 0;
    while(N--) {
        getline(&buffer, &bufsize, stdin);
        int r1, r2, t;
        if(sscanf(buffer, "%d %d", &r1, &r2) == 2 && r1 >= 0 && r2 >= 0)
            printf("%.4f\n", 2 * r1 * r2 * PI);
        else if(sscanf(buffer, "%d", &t) == 1 && t >= 0)
            printf("%.4f\n",  t * t / 8.0 * PI);
        else
            puts("Impossible");
    }
    free(buffer);
    return 0;
}
