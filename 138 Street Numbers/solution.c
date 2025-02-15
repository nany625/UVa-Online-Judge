// #解法一(捷徑)
#include <stdio.h>

int main() {
    puts("         6         8\n"
         "        35        49\n"
         "       204       288\n"
         "      1189      1681\n"
         "      6930      9800\n"
         "     40391     57121\n"
         "    235416    332928\n"
         "   1372105   1940449\n"
         "   7997214  11309768\n"
         "  46611179  65918161");
    return 0;
}

// #解法二
#include <stdio.h>
#include <math.h>

int main() {
    int count = 0;
    long n = 2;
    while(count < 10) {
        double k = ((-(n << 1) - 1) + sqrt((n * n << 3) + 1)) / 2;
        if(k == (int)k) {
            printf("%10ld%10ld\n", n, n + (int)k);
            ++count;
        }
        ++n;
    }
    return 0;
}
