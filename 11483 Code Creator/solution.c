#include <stdio.h>
#include <string.h>

int main() {
    int cases = 0, N;
    char buffer[102];
    while(scanf("%d", &N) && N != 0) {
        getchar();
        printf("Case %d:\n", ++cases);
        puts("#include<string.h>");
        puts("#include<stdio.h>");
        puts("int main()");
        puts("{");
        while(N--) {
            fgets(buffer, sizeof(buffer), stdin);
            printf("printf(\"");
            int len = strlen(buffer);
            for(int i = 0; i < len - 1; ++i) {
                if(buffer[i] == '"' || buffer[i] == '\\')
                    printf("\\");
                putchar(buffer[i]);
            }
            puts("\\n\");");
        }
        puts("printf(\"\\n\");");
        puts("return 0;");
        puts("}");
    }
    return 0;
}
