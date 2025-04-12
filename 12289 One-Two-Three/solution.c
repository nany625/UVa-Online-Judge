#include <stdio.h>
#include <string.h>

char words[][6] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"}, word[11];

int solve(char *array) {
    int len = strlen(array);
    for(int i = 0; i < 10; ++i) {
        if(len == strlen(words[i])) {
            int count = 0;
            for(int j = 0; j < len; ++j)
                count += array[j] != words[i][j];
            if(count <= 1)
                return i + 1;
        }
    }
}

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        scanf("%s", word);
        printf("%d\n", solve(word));
    }
    return 0;
}
