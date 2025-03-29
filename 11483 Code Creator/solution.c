#include <stdio.h>
#include <string.h>

int main() {
    int cases = 0, N;
    char buffer[102];
    while(scanf("%d ", &N) && N != 0) {
        printf("Case %d:\n#include<string.h>\n#include<stdio.h>\nint main()\n{\n", ++cases);
        while(N--) {
            fgets(buffer, sizeof(buffer), stdin);
            fputs("printf(\"", stdout);
            int len = strlen(buffer);
            for(int i = 0; i < len - 1; ++i) {
                if(buffer[i] == '"' || buffer[i] == '\\')
                    putchar('\\');
                putchar(buffer[i]);
            }
            puts("\\n\");");
        }
        puts("printf(\"\\n\");\nreturn 0;\n}");
    }
    return 0;
}
