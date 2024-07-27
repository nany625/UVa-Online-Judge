#include <stdio.h>
#include <string.h>

char HaabMonth[][7] = {
    "pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", 
    "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"
};

char TzolkinName[][9] = {
    "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", 
    "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"
};

int monthToNum(char *key) {
    for(int i = 0; i < 19; ++i) {
        if(strcmp(HaabMonth[i], key) == 0)
            return i;
    }
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%d\n", n);
    int day, year;
    char month[7];
    while(n--) {
        scanf("%d %*c %s %d", &day, month, &year);
        int totalDays = day + 20 * monthToNum(month) + 365 * year;
        printf("%d %s %d\n", totalDays % 13 + 1, TzolkinName[totalDays % 20], totalDays / 260);
    }
    return 0;
}
