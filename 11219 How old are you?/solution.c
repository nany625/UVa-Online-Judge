#include <stdio.h>

typedef struct {
    int year, month, day;
} Date;

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        Date curr, birth;
        scanf("%d %*c %d %*c %d %d %*c %d %*c %d", &curr.day, &curr.month, &curr.year, &birth.day, &birth.month, &birth.year);
        if(birth.year * 10000 + birth.month * 100 + birth.day > curr.year * 10000 + curr.month * 100 + curr.day)
            printf("Case #%d: Invalid birth date\n", i);
        else {
            int age = curr.year - birth.year - (birth.month * 100 + birth.day > curr.month * 100 + curr.day);
            if(age > 130)
                printf("Case #%d: Check birth date\n", i);
			else
				printf("Case #%d: %d\n", i, age);
        }
    }
    return 0;
}
