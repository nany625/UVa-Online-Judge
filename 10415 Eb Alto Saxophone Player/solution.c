#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int t;
    scanf("%d", &t);
    getchar();
    char *buffer = NULL;
    size_t bufsize = 0;
    while(t--) {
        getline(&buffer, &bufsize, stdin);
        buffer[strcspn(buffer, "\n")] = '\0';
        int press[10] = {}, len = strlen(buffer);
        char prev[11] = "0000000000", curr[11];
        for(int i = 0; i < len; ++i) {
            switch(buffer[i]) {
                case 'c':
					strcpy(curr, "0111001111");
					break;
				case 'd':
					strcpy(curr, "0111001110");
					break;
				case 'e':
					strcpy(curr, "0111001100");
					break;
				case 'f':
					strcpy(curr, "0111001000");
					break;
				case 'g':
					strcpy(curr, "0111000000");
					break;
				case 'a':
					strcpy(curr, "0110000000");
					break;
				case 'b':
					strcpy(curr, "0100000000");
					break;
				case 'C':
					strcpy(curr, "0010000000");
					break;
				case 'D':
					strcpy(curr, "1111001110");
					break;
				case 'E':
					strcpy(curr, "1111001100");
					break;
				case 'F':
					strcpy(curr, "1111001000");
					break;
				case 'G':
					strcpy(curr, "1111000000");
					break;
				case 'A':
					strcpy(curr, "1110000000");
					break;
				case 'B':
					strcpy(curr, "1100000000");
            }
            for(int j = 0; j < 10; ++j) {
                if(j == 4 || j == 5)
                    continue;
                press[j] += curr[j] > prev[j];
            }
            strcpy(prev, curr);
        }
        for(int j = 0; j < 9; ++j)
            printf("%d ", press[j]);
        printf("%d\n", press[9]);
    }
    free(buffer);
    return 0;
}
