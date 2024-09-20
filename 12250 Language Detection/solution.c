#include <stdio.h>
#include <string.h>

int main() {
    int cases = 0;
	char S[15];
	while(scanf("%s", S) && S[0] != '#') {
	    if(strcmp(S, "HELLO") == 0)
	        printf("Case %d: ENGLISH\n", ++cases);
	    else if(strcmp(S, "HOLA") == 0)
	        printf("Case %d: SPANISH\n", ++cases);
	    else if(strcmp(S, "HALLO") == 0)
	        printf("Case %d: GERMAN\n", ++cases);
	    else if(strcmp(S, "BONJOUR") == 0)
	        printf("Case %d: FRENCH\n", ++cases);
	    else if(strcmp(S, "CIAO") == 0)
	        printf("Case %d: ITALIAN\n", ++cases);
	    else if(strcmp(S, "ZDRAVSTVUJTE") == 0)
	        printf("Case %d: RUSSIAN\n", ++cases);
	    else
	        printf("Case %d: UNKNOWN\n", ++cases);
	}
	return 0;
}
