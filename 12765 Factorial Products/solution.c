#include <stdio.h>
#include <stdbool.h>

int table[][4] = {
    {}, 
    {}, 
    {1, 0, 0, 0}, 
    {1, 1, 0, 0}, 
    {3, 1, 0, 0}, 
    {3, 1, 1, 0}, 
    {4, 2, 1, 0}, 
    {4, 2, 1, 1}, 
    {7, 2, 1, 1}, 
    {7, 4, 1, 1}
};

bool equal(int *array1, int *array2) {
    for(int i = 0; i < 4; ++i) {
        if(array1[i] != array2[i])
            return false;
    }
    return true;
}

int main() {
    int N, M;
    while(scanf("%d %d", &N, &M) && N != 0 && M != 0) {
        int generator1[4] = {}, generator2[4] = {}, digit;
        while(N--) {
            scanf("%d", &digit);
            for(int i = 0; i < 4; ++i)
                generator1[i] += table[digit][i];
        }
        while(M--) {
            scanf("%d", &digit);
            for(int i = 0; i < 4; ++i)
                generator2[i] += table[digit][i];
        }
        puts(equal(generator1, generator2) ? "YES" : "NO");
    }
    return 0;
}
