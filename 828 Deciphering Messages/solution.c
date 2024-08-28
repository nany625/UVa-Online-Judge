#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

char deciph(char ch, int N) {
    return (ch - 'A' + 26 - N) % 26 + 'A';
}

int main() {
    int cases;
    scanf("%d", &cases);
    char *buffer = NULL;
    size_t bufsize = 0;
    while(cases--) {
        char *alphaKey = NULL;
        int numericalKey, messages;
        scanf("%ms %d %d", &alphaKey, &numericalKey, &messages);
        bool L[26] = {};
        int alphaKeyLen = strlen(alphaKey);
        for(int i = 0; i < alphaKeyLen; ++i)
            L[alphaKey[i] - 'A'] = true;
        getchar();
        while(messages--) {
            getline(&buffer, &bufsize, stdin);
            char *plaintext = NULL;
            int size = 0, m = 0, curr = 0, len = strlen(buffer);
            bool error = false;
            while(curr < len && !error) {
                if(!isupper(buffer[curr])) {
                    plaintext = (char*)realloc(plaintext, (size + 2) * sizeof(char));
                    plaintext[size++] = buffer[curr++];
                } else {
                    if(curr < len - 2 && isupper(buffer[curr + 1]) && isupper(buffer[curr + 2])) {
                        if(buffer[curr] == alphaKey[m] && buffer[curr + 2] == alphaKey[(m + 1) % alphaKeyLen]) {
                            char deciphChar = deciph(buffer[curr + 1], numericalKey);
                            if(L[deciphChar - 'A']) {
                                plaintext = (char*)realloc(plaintext, (size + 2) * sizeof(char));
                                plaintext[size++] = deciphChar;
                                ++m %= alphaKeyLen;
                                curr += 3;
                            } else
                                error = true;
                        } else {
                            char deciphChar = deciph(buffer[curr], numericalKey);
                            if(!L[deciphChar - 'A']) {
                                plaintext = (char*)realloc(plaintext, (size + 2) * sizeof(char));
                                plaintext[size++] = deciphChar;
                                ++curr;
                            } else
                                error = true;
                        }
                    } else {
                        char deciphChar = deciph(buffer[curr], numericalKey);
                        if(!L[deciphChar - 'A']) {
                            plaintext = (char*)realloc(plaintext, (size + 2) * sizeof(char));
                            plaintext[size++] = deciphChar;
                            ++curr;
                        } else
                            error = true;
                    }
                }
            }
            if(!error) {
                plaintext[size] = '\0';
                fputs(plaintext, stdout);
            } else
                puts("error in encryption");
            free(plaintext); 
        }
        free(alphaKey);
        if(cases)
            putchar('\n');
    }
    free(buffer);
    return 0;
}
