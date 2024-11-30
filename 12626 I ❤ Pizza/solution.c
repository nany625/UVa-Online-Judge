#include <stdio.h>
#include <string.h>

int requirement[] = {3, 1, 1, 1, 2, 1};

int main() {
    int N;
    scanf("%d", &N);
    char ingredients[601];  
    while(N--) {
        scanf("%s", ingredients);
        int count[6] = {}, len = strlen(ingredients);
        for(int i = 0; i < len; ++i) {
            switch(ingredients[i]) {
                case 'A':
                    ++count[0];
                    break;
                case 'G':
                    ++count[1];
                    break;
                case 'I':
                    ++count[2];
                    break;
                case 'M':
                    ++count[3];
                    break;
                case 'R':
                    ++count[4];
                    break;
                case 'T':
                    ++count[5];
            }
        }
        int min = count[0] / 3;
        for(int i = 1; i < 6; ++i)
            min = min < count[i] / requirement[i] ? min : count[i] / requirement[i];
        printf("%d\n", min);
    }
    return 0;
}
