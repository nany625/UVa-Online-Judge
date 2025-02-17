#include <stdio.h>

int main() {
    int s, p, y, j;
    while(scanf("%d %d %d %d", &s, &p, &y, &j) == 4) {
        int Y = (12 + j - p - y) / 3;
        switch((12 + j - p - y) % 3) {
            case 0:
                printf("%d %d %d\n", Y + y, Y + p, Y);
                break;
            case 1:
                printf("%d %d %d\n", Y + y + (s + p == y), Y + p + (s + p != y), Y);
                break;
            case 2:
                printf("%d %d %d\n", Y + y + 1, Y + p + 1, Y);
        }
    }
	return 0;
}
