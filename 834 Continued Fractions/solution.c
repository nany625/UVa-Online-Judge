#include <stdio.h>

int main() {
    int numerator, denominator;
    while(scanf("%d %d", &numerator, &denominator) == 2) {
        int count = 0;
        do {
            if(count == 0)
                printf("[%d", numerator / denominator);
            else if(count == 1)
		        printf(";%d", numerator / denominator);
		    else
		        printf(",%d", numerator / denominator);
			int temp = numerator %= denominator;
		    numerator = denominator;
		    denominator = temp;
	        ++count;
        } while(denominator > 0);
        puts("]");
    }
	return 0;
}
