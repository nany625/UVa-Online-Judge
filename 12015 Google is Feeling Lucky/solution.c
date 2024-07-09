#include <stdio.h>
#include <stdlib.h>
#include <string.h>
	
typedef struct {
    char *url;
    short relevance;
} Webpage;

Webpage webpages[10];

int main() {
    int T;
    scanf("%d", &T);
    for(int i = 1; i <= T; ++i) {
        printf("Case #%d:\n", i);
        short max = 0;
        for(int j = 0; j < 10; ++j) {
            webpages[j].url = NULL;
            scanf("%ms %hd", &webpages[j].url, &webpages[j].relevance);
            max = max > webpages[j].relevance ? max : webpages[j].relevance;
        }
        for(int j = 0; j < 10; ++j) {
            if(webpages[j].relevance == max)
                printf("%s\n", webpages[j].url);
            free(webpages[j].url);
        }
    }
    return 0;
}
