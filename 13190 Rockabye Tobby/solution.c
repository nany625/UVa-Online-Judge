#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    int frequency, next;
} Medicine;

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n, k;
        scanf("%d %d", &n, &k);
        Medicine medicines[n];
        for(int i = 0; i < n; ++i) {
            medicines[i].name = NULL;
            scanf("%ms %d", &medicines[i].name, &medicines[i].frequency);
            medicines[i].next = medicines[i].frequency;
        }
        while(k) {
            int min = medicines[0].next;
            for(int i = 1; i < n; ++i)
                min = min < medicines[i].next ? min : medicines[i].next;
            for(int i = 0; i < n && k; ++i) {
				if(min == medicines[i].next){
					printf("%d %s\n", min, medicines[i].name);
					medicines[i].next += medicines[i].frequency;
					--k;
				}
			}
        }
        for(int i = 0; i < n; ++i)
            free(medicines[i].name);
    }
	return 0;
}
