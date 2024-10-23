#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);
    while(n--) {
        int k, w;
        scanf("%d %d", &k, &w);
        char message[k + 1];
        scanf("%s", message);
        char *sign = strdup(message);
        while(w-- > 1) {
            scanf("%s", message);
            int temp = k, len = strlen(sign);
            while(temp > 0 && strncmp(sign + len - temp, message, temp) != 0)
                --temp;
            sign = (char*)realloc(sign, (len + k - temp + 1) * sizeof(char));
            strcat(sign, message + temp);
        }
        printf("%d\n", (int)strlen(sign));
        free(sign);
    }
	return 0;
}
