#include <stdio.h>
#include <stdlib.h>

int main() {
    long Hashmat, opponent;
    while(scanf("%ld %ld", &Hashmat, &opponent) == 2)
        printf("%ld\n", labs(Hashmat - opponent));
    return 0;
}
