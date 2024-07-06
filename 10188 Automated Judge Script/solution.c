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
		    int i = 0, j = 0, lenSolution = strlen(solution), lenOutput = strlen(output);
		    while(i < lenSolution && j < lenOutput) {
		        while(i < lenSolution && !isdigit(solution[i]))
		            ++i;
		        while(j < lenOutput && !isdigit(output[j]))
		            ++j;
		        if(i < lenSolution && j < lenOutput) {
		            if(solution[i] != output[j])
		                break;
		            ++i;
		            ++j;
		        } else
                    break;
		    }
		    if(i == lenSolution && j == lenOutput)
		        printf("Run #%d: Presentation Error\n", ++x);
		    else
		        printf("Run #%d: Wrong Answer\n", ++x);
		}
		free(solution);
		free(output);
	}
	return 0;
}
