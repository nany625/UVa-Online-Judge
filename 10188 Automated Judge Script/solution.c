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
	    char *teamOutput = (char*)malloc(sizeof(char));
	    teamOutput[0] = '\0';
	    while(m--) {
	        fgets(line, sizeof(line), stdin);
	        teamOutput = (char*)realloc(teamOutput, (strlen(teamOutput) + strlen(line) + 1) * sizeof(char));
	        strcat(teamOutput, line);
	    }
	    if(strcmp(solution, teamOutput) == 0)	
			printf("Run #%d: Accepted\n", ++x);
		else {
		    int i = 0, j = 0, lenSolution = strlen(solution), lenteamOutput = strlen(teamOutput);
		    while(i < lenSolution && j < lenteamOutput) {
		        while(i < lenSolution && !isdigit(solution[i]))
		            ++i;
		        while(j < lenteamOutput && !isdigit(teamOutput[j]))
		            ++j;
		        if(i < lenSolution && j < lenteamOutput) {
		            if(solution[i] != teamOutput[j])
		                break;
		            ++i;
		            ++j;
		        } else
                    break;
		    }
		    if(i == lenSolution && j == lenteamOutput)
		        printf("Run #%d: Presentation Error\n", ++x);
		    else
		        printf("Run #%d: Wrong Answer\n", ++x);
		}
		free(solution);
		free(teamOutput);
	}
	return 0;
}
