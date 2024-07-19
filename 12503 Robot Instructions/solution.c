#include <stdio.h>

int main() {
    char command[6];
    int T;
    scanf("%d", &T);
	while(T--) {
		int n;
        scanf("%d", &n);
		int instructions[n], p = 0;
		for(int i = 0; i < n; ++i) {
		    scanf("%s", command);
		    switch(command[0]) {
		        case 'L':
                    p += (instructions[i] = -1);
                    break;
                case 'R':
                    p += (instructions[i] = 1);
                    break;
                case 'S':
                    scanf("%s", command);
                    int temp;
                    scanf("%d", &temp);
                    p += (instructions[i] = instructions[temp - 1]);
		    }
		}
		printf("%d\n", p);
	}

    return 0;
}
