#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);
        int sequence[n];
        for(int i = 0; i < n; ++i)
            scanf("%d", &sequence[i]);
        int limit = 36;
        while(limit--) {
            bool ZERO = true;
            for(int i = 0; i < n && ZERO; ++i) {
                if(sequence[i] != 0)
                    ZERO = false;
            }
            if(ZERO)
                break;
            int temp = sequence[0];
            for(int i = 0; i < n - 1; ++i)
                sequence[i] = abs(sequence[i + 1] - sequence[i]);
            sequence[n - 1] = abs(temp - sequence[n - 1]);
        }
        printf("%s\n", limit > 0 ? "ZERO" : "LOOP");
    }
	return 0;
}
