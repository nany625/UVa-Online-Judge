#include <stdio.h>
#include <string.h>

int main() {
    int RFP = 0, n, p;
    char buffer[82], name[82];
    while(scanf("%d %d ", &n, &p) && n != 0 && p != 0) {
        if(RFP)
            putchar('\n');
        while(n--)
            fgets(buffer, sizeof(buffer), stdin);
        double minR;
        int maxD = -1;
        while(p--) {
            fgets(buffer, sizeof(buffer), stdin);
            double r;
            int d;
            scanf("%lf %d ", &r, &d);
            if(d > maxD) {
                strcpy(name, buffer);
                minR = r;
                maxD = d;
            } else if(d == maxD && r < minR) {
                strcpy(name, buffer);
                minR = r;
            }
            while(d--)
                fgets(buffer, sizeof(buffer), stdin);
        }
        printf("RFP #%d\n%s", ++RFP, name);
    }
    return 0;
}
