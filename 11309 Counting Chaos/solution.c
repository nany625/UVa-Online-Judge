#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        int HH, MM;
        scanf("%d %*c %d", &HH, &MM);
        if(HH == 0) {
            if(MM < 9)
                printf("00:%02d\n", MM + 1);
            else if(MM < 55)
                printf("00:%d\n", 11 * (MM / 11 + 1));
            else
                puts("01:01");
        } else if(HH < 10) {
            if(MM < 50 + HH) {
                if(MM % 10 < HH)
                    printf("%02d:%02d\n", HH, 10 * (MM / 10) + HH);
                else
                    printf("%02d:%d\n", HH, 10 * (MM / 10 + 1) + HH);
            } else {
                if(HH < 9)
                    printf("%02d:%02d\n", HH + 1, HH + 1);
                else
                    puts("10:01");
            }
        } else if(HH < 16) {
            if(MM < HH % 10 * 10 + HH / 10)
                printf("%d:%02d\n", HH, HH % 10 * 10 + HH / 10);
            else {
                ++HH;
                if(HH < 16)
                    printf("%d:%d\n", HH, HH % 10 * 10 + HH / 10);
                else
                    puts("20:02");
            }
        } else if(HH < 20)
            puts("20:02");
        else if(HH < 23) {
            if(MM < HH % 10 * 10 + HH / 10)
                printf("%d:%02d\n", HH, HH % 10 * 10 + HH / 10);
            else {
                ++HH;
                printf("%d:%d\n", HH, HH % 10 * 10 + HH / 10);
            }
        } else
            puts(MM < 32 ? "23:32" : "00:00");
    }
    return 0;
}
