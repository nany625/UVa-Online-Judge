#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    short problem, times;
} ProblemTried;

typedef struct {
    short contestant, *solvedProblems, solvedCount, unsolvedCount, penaltyTime;
    ProblemTried *problemTried;
} ScoreBoard;

int containContestant(ScoreBoard *array, int size, short key) {
    for(int i = 0; i < size; ++i) {
        if(array[i].contestant == key)
            return i;
    }
    return -1;
}

bool containSolved(short *array, int size, short key) {
    for(int i = 0; i < size; ++i) {
        if(array[i] == key)
            return true;
    }
    return false;
}

int containUnsolved(ProblemTried *array, int size, short key) {
    for(int i = 0; i < size; ++i) {
        if(array[i].problem == key)
            return i;
    }
    return -1;
}

int compare(const void *a, const void *b) {
    ScoreBoard *s1 = (ScoreBoard*)a;
    ScoreBoard *s2 = (ScoreBoard*)b;
    if(s1->solvedCount != s2->solvedCount)
        return s1->solvedCount < s2->solvedCount;
    if(s1->penaltyTime != s2->penaltyTime)
        return s1->penaltyTime > s2->penaltyTime;
    return s1->contestant > s2->contestant;
}

int main() {
	int cases;
	scanf("%d  ", &cases);
    char *buffer = NULL;
	size_t bufsize = 0;
	while(cases--) {
	    ScoreBoard *scoreBoards = NULL;
	    int contestantCount = 0;
	    while(getline(&buffer, &bufsize, stdin) != -1 && buffer[0] != '\n') {
	        short contestant, problem, time;
	        char L;
	        sscanf(buffer, "%hd %hd %hd %c", &contestant, &problem, &time, &L);
	        int contestantPos = containContestant(scoreBoards, contestantCount, contestant);
    	    if(contestantPos != -1) {
    	        if(L == 'C') {
    	            if(!containSolved(scoreBoards[contestantPos].solvedProblems, scoreBoards[contestantPos].solvedCount, problem)) {
    	                scoreBoards[contestantPos].solvedProblems = (short*)realloc(scoreBoards[contestantPos].solvedProblems, (scoreBoards[contestantPos].solvedCount + 1) * sizeof(short));
        	            scoreBoards[contestantPos].solvedProblems[scoreBoards[contestantPos].solvedCount++] = problem;
    	                int problemPos = containUnsolved(scoreBoards[contestantPos].problemTried, scoreBoards[contestantPos].unsolvedCount, problem);
    	                if(problemPos != -1) {
            	            scoreBoards[contestantPos].penaltyTime += time + 20 * scoreBoards[contestantPos].problemTried[problemPos].times;
            	            scoreBoards[contestantPos].problemTried[problemPos] = scoreBoards[contestantPos].problemTried[--scoreBoards[contestantPos].unsolvedCount];
    	                } else
    	                    scoreBoards[contestantPos].penaltyTime += time;
    	            }
    	        } else if(L == 'I') {
    	            int problemPos = containUnsolved(scoreBoards[contestantPos].problemTried, scoreBoards[contestantPos].unsolvedCount, problem);
    	            if(problemPos != -1)
    	                ++scoreBoards[contestantPos].problemTried[problemPos].times;
    	            else {
    	                scoreBoards[contestantPos].problemTried = (ProblemTried*)realloc(scoreBoards[contestantPos].problemTried, (scoreBoards[contestantPos].unsolvedCount + 1) * sizeof(ProblemTried));
    	                scoreBoards[contestantPos].problemTried[scoreBoards[contestantPos].unsolvedCount].problem = problem;
    	                scoreBoards[contestantPos].problemTried[scoreBoards[contestantPos].unsolvedCount++].times = 1;
    	            }
    	        }
    	    } else {
    	        scoreBoards = (ScoreBoard*)realloc(scoreBoards, (contestantCount + 1) * sizeof(ScoreBoard));
    	        scoreBoards[contestantCount].contestant = contestant;
    	        scoreBoards[contestantCount].solvedProblems = NULL;
    	        scoreBoards[contestantCount].problemTried = NULL;
    	        scoreBoards[contestantCount].solvedCount = 0;
    	        scoreBoards[contestantCount].unsolvedCount = 0;
    	        scoreBoards[contestantCount].penaltyTime = 0;
    	        if(L == 'C') {
    	            scoreBoards[contestantCount].solvedProblems = (short*)realloc(scoreBoards[contestantCount].solvedProblems, (scoreBoards[contestantCount].solvedCount + 1) * sizeof(short));
    	            scoreBoards[contestantCount].solvedProblems[scoreBoards[contestantCount].solvedCount++] = problem;
    	            scoreBoards[contestantCount].penaltyTime = time;
    	        } else if(L == 'I') {
    	            scoreBoards[contestantCount].problemTried = (ProblemTried*)realloc(scoreBoards[contestantCount].problemTried, (scoreBoards[contestantCount].unsolvedCount + 1) * sizeof(ProblemTried));
    	            scoreBoards[contestantCount].problemTried[scoreBoards[contestantCount].unsolvedCount].problem = problem;
    	            scoreBoards[contestantCount].problemTried[scoreBoards[contestantCount].unsolvedCount++].times = 1;
    	        }
    	        ++contestantCount;
    	    }
	    }
	    qsort(scoreBoards, contestantCount, sizeof(ScoreBoard), compare);
	    for(int i = 0; i < contestantCount; ++i) {
	        printf("%hd %hd %hd\n", scoreBoards[i].contestant, scoreBoards[i].solvedCount, scoreBoards[i].penaltyTime);
	        free(scoreBoards[i].solvedProblems);
	        free(scoreBoards[i].problemTried);
	    }
	    free(scoreBoards);
	    if(cases)
	        putchar('\n');
	}
    free(buffer);
	return 0;
}
