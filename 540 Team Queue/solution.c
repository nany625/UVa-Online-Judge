#include <stdio.h>
#include <stdlib.h>

int teamNum[1000000];

typedef struct Queue {
    int data;
    struct Queue *prev, *next;
} Queue;

int main() {
	int cases = 0, t;
	while(scanf("%d", &t) && t != 0) {
	    printf("Scenario #%d\n", ++cases);
	    int elementCount;
	    for(int i = 0; i < t; ++i) {
	        scanf("%d", &elementCount);
	        while(elementCount--) {
	            int element;
	            scanf("%d", &element);
	            teamNum[element] = i;
	        }
	    }
	    Queue *head = NULL, *tail = NULL, *nextDequeue = NULL;
	    char command[8];
	    while(scanf("%s", command) && command[0] != 'S') {
	        if(command[0] == 'E') {
	            Queue *newNode = (Queue*)malloc(sizeof(Queue));
	            scanf("%d", &newNode->data);
	            newNode->prev = tail;
	            newNode->next = NULL;
	            if(!head)
	                head = nextDequeue = newNode;
	            else
	                tail->next = newNode;
	            tail = newNode;
	        } else if(command[0] == 'D') {
	            printf("%d\n", nextDequeue->data);
	            int currTeam = teamNum[nextDequeue->data];
	            Queue *temp;
	            if(nextDequeue == head) {
	                temp = head;
	                head = head->next;
	            } else if(nextDequeue == tail) {
	                temp = tail;
	                tail = tail->prev;
	                tail->next = NULL;
	            } else {
	                temp = nextDequeue;
	                nextDequeue->prev->next = nextDequeue->next;
	                nextDequeue->next->prev = nextDequeue->prev;
	            }
	            free(temp);
	            do {
	                nextDequeue = nextDequeue->next;
	            } while(nextDequeue && teamNum[nextDequeue->data] != currTeam);
	            if(!nextDequeue)
	                nextDequeue = head;
	        }
	    }
	    putchar('\n');
	    while(head) {
	        Queue *temp = head;
	        head = head->next;
	        free(temp);
	    }
	}
	return 0;
}
