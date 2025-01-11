#include <stdio.h>
#include <string.h>

int main() {
    char name[11], num[51], temp[6];
    while(scanf("%s", name) == 1) {
        int ST = 1, nameLen = strlen(name);
        while(ST <= 10000) {
            num[0] = '\0';
            for(int i = 0; i < nameLen; ++i) {
                sprintf(temp, "%d", name[i] - 'A' + ST);
                strcat(num, temp);
            }
            int numLen = strlen(num);
            int YuanFen[numLen - 2][numLen];
            for(int i = 0; i < numLen; ++i)
                YuanFen[0][i] = num[i] - '0';
            for(int i = 1; i < numLen - 2; ++i) {
                for(int j = 0; j < numLen - i; ++j)
                    YuanFen[i][j] = (YuanFen[i - 1][j] + YuanFen[i - 1][j + 1]) % 10;
            }
            if(YuanFen[numLen - 3][0] == 1 && YuanFen[numLen - 3][1] == 0 && YuanFen[numLen - 3][2] == 0)
                break;
            ++ST;
        }
        if(ST <= 10000)
            printf("%d\n", ST);
        else
            puts(":(");
    }
    return 0;
}
