#include <stdio.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);
    int magenta, yellow, cyan;
    char pixels[100001];
    while(t--) {
        scanf("%d %d %d %s", &magenta, &yellow, &cyan, pixels);
        int len = strlen(pixels);
        for(int i = 0; i < len && magenta >= 0 && yellow >= 0 && cyan >= 0; ++i) {
            switch(pixels[i]) {
                case 'M':
                    --magenta;
                    break;
                case 'Y':
                    --yellow;
                    break;
                case 'C':
                    --cyan;
                    break;
                case 'R':
                    --magenta;
                    --yellow;
                    break;
                case 'B':
                    --magenta;
                    --yellow;
                    --cyan;
                    break;
                case 'G':
                    --yellow;
                    --cyan;
                    break;
                case 'V':
                    --magenta;
                    --cyan;
            }
        }
        if(magenta >= 0 && yellow >= 0 && cyan >= 0)
            printf("YES %d %d %d\n", magenta, yellow, cyan);
        else
            puts("NO");
            
    }
	return 0;
}
