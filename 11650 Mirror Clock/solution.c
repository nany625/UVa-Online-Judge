#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int HH, MM;
        scanf("%d:%d", &HH, &MM);
        if(MM == 0) {
            if(HH == 12)
                puts("12:00");
            else
                printf("%02d:00\n", 12 - HH);
        } else {
            if(HH == 12)
                printf("11:%02d\n", 60 - MM);
            else if(HH == 11)
                printf("12:%02d\n", 60 - MM);
            else
                printf("%02d:%02d\n", 11 - HH, 60 - MM);
        }
    }
    return 0;
}
