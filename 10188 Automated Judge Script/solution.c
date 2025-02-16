#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
	int x = 0, n;
    char buffer[122];
	while(scanf("%d", &n) && n != 0) {
	    char *solution = strdup("");
	    fgets(buffer, sizeof(buffer), stdin);
	    while(n--) {
	        fgets(buffer, sizeof(buffer), stdin);
	        solution = (char*)realloc(solution, (strlen(solution) + strlen(buffer) + 1) * sizeof(char));
	        strcat(solution, buffer);
	    }
	    int m;
	    scanf("%d", &m);
	    char *teamOutput = strdup("");
	    fgets(buffer, sizeof(buffer), stdin);
	    while(m--) {
	        fgets(buffer, sizeof(buffer), stdin);
	        teamOutput = (char*)realloc(teamOutput, (strlen(teamOutput) + strlen(buffer) + 1) * sizeof(char));
	        strcat(teamOutput, buffer);
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
