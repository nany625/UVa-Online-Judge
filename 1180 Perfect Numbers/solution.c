#include <stdio.h>
#include <stdbool.h>

int primes[] = {2, 3, 5, 7, 13, 17};

int main() {
    scanf("%*d");
    int p;
    while(scanf("%d%*c", &p) == 1) {
        bool perfect = false;
        for(int i = 0; i < 6 && !perfect; ++i) {
            if(primes[i] == p)
                perfect = true;
        }
        puts(perfect ? "Yes" : "No");
    }
    return 0;
}
