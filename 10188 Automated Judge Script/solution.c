#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
	int x = 0, n;
	while(scanf("%d", &n) && n != 0) {
	    getchar();
	    char *solution = (char*)malloc(sizeof(char)), line[122];
	    solution[0] = '\0';
	    while(n--) {
	        fgets(line, sizeof(line), stdin);
	        solution = (char*)realloc(solution, (strlen(solution) + strlen(line) + 1) * sizeof(char));
	        strcat(solution, line);
	        
	    }
	    int m;
	    scanf("%d", &m);
	    getchar();
	    char *output = (char*)malloc(sizeof(char));
	    output[0] = '\0';
	    while(m--) {
	        fgets(line, sizeof(line), stdin);
	        output = (char*)realloc(output, (strlen(output) + strlen(line) + 1) * sizeof(char));
	        strcat(output, line);
	    }
	    if(strcmp(solution, output) == 0)	
			printf("Run #%d: Accepted\n", ++x);
		else {
		    char *solutionNum = (char*)malloc(sizeof(char)), *outputNum = (char*)malloc(sizeof(char));
		    solutionNum[0] = outputNum[0] = '\0';
		    int len = strlen(solution);
		    for(int i = 0; i < len; ++i) {
		        if(isdigit(solution[i])) {
		            int lenNum = strlen(solutionNum);
		            solutionNum = (char*)realloc(solutionNum, (lenNum + 2) * sizeof(char));
		            solutionNum[lenNum] = solution[i];
		            solutionNum[lenNum + 1] = '\0';
		        }
		    }
		    len = strlen(output);
		    for(int i = 0; i < len; ++i) {
		        if(isdigit(output[i])) {
		            int lenNum = strlen(outputNum);
		            outputNum = (char*)realloc(outputNum, (lenNum + 2) * sizeof(char));
		            outputNum[lenNum] = output[i];
		            outputNum[lenNum + 1] = '\0';
		        }
		    }
		    if(strcmp(solutionNum, outputNum) == 0)
		        printf("Run #%d: Presentation Error\n", ++x);
		    else
		        printf("Run #%d: Wrong Answer\n", ++x);
		    free(solutionNum);
		    free(outputNum);
		}
		free(solution);
		free(output);
	}
	return 0;
}
