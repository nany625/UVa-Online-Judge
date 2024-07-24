#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char Character[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
char Reverse[] = "A---3--HIL-JM-O---2TUVWXY51SE-Z--8-";

int main() {
    char s[21];
    while(scanf("%s", s) == 1) {
        int len = strlen(s);
        bool isPalindrome = true;
        for(int i = 0; i < len / 2 && isPalindrome; ++i)
            isPalindrome = s[i] == s[len - 1 - i];
        bool isMirror = true;
        for(int i = 0; i < (len + 1) / 2 && isMirror; ++i) {
            for(int j = 0; j < 35 && isMirror; ++j) {
                if(s[i] == Character[j] && Reverse[j] != s[len - 1 - i])
                    isMirror = false;
            }
        }
        if(isPalindrome && isMirror)
            printf("%s -- is a mirrored palindrome.\n\n", s);
        else if(isPalindrome)
            printf("%s -- is a regular palindrome.\n\n", s);
        else if(isMirror)
            printf("%s -- is a mirrored string.\n\n", s);
        else
            printf("%s -- is not a palindrome.\n\n", s);
    }
    return 0;
}
