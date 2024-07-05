#include <stdio.h>

int main() {
    long Hashmat, opponent;
    while(scanf("%ld %ld", &Hashmat, &opponent) == 2)
        printf("%ld\n", Hashmat > opponent ? Hashmat - opponent : opponent - Hashmat);
    return 0;
}
