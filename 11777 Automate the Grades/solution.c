#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        printf("Case %d: ", i);
        int Term1, Term2, Final, Attendance, classes[3];
        scanf("%d %d %d %d", &Term1, &Term2, &Final, &Attendance);
        for(int j = 0; j < 3; ++j)
            scanf("%d", &classes[j]);
        if(classes[0] < classes[1])
            swap(&classes[0], &classes[1]);
        if(classes[1] < classes[2])
            swap(&classes[1], &classes[2]);
        int marks = Term1 + Term2 + Final + Attendance + (classes[0] + classes[1] >> 1);
        if(marks >= 90)
            puts("A");
        else if(marks >= 80)
            puts("B");
        else if(marks >= 70)
            puts("C");
        else if(marks >= 60)
            puts("D");
        else
            puts("F");
    }
	return 0;
}
