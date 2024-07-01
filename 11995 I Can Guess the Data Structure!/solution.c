#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
        
void append(short **structure, short *size, short data) {
    *structure = (short*)realloc(*structure, (*size + 1) * sizeof(short));
    (*structure)[(*size)++] = data;
}

void removeElement(short **structure, short *size, int index) {
    for(int i = index; i < *size - 1; ++i)
        (*structure)[i] = (*structure)[i + 1];
    --(*size);
}

int contain(short *structure, short size, short data) {
    for(int i = 0; i < size; ++i) {
        if(structure[i] == data)
            return i;
    }
    return -1;
}

int main() {
    int n;
    while(scanf("%d", &n) == 1) {
        short *stack = NULL, *queue = NULL, *priorityQueue = NULL;
        short stackSize = 0, queueSize = 0, priorityQueueSize = 0, max = 1;
        bool isStack = true, isQueue = true, isPriorityQueue = true;
        while(n--) {
            int command;
            short x;
            scanf("%d %hd", &command, &x);
            if(command == 1) {
                append(&stack, &stackSize, x);
                append(&queue, &queueSize, x);
                append(&priorityQueue, &priorityQueueSize, x);
                max = max > x ? max : x;
            } else if(command == 2) {
                int index = contain(priorityQueue, priorityQueueSize, x);
                if(index == -1)
                    isStack = isQueue = isPriorityQueue = false;
                else {
                    if(isStack) {
                        if(x == stack[stackSize - 1])
                            removeElement(&stack, &stackSize, stackSize - 1);
                        else
                            isStack = false;
                    }
                    if(isQueue) {
                        if(x == queue[0])
                            removeElement(&queue, &queueSize, 0);
                        else
                            isQueue = false;
                    }
                    removeElement(&priorityQueue, &priorityQueueSize, index);
                    if(x == max) {
                        max = 1;
                        for(int i = 0; i < priorityQueueSize; ++i)
                            max = max > priorityQueue[i] ? max : priorityQueue[i];
                    } else
                        isPriorityQueue = false;
                }
            }
        }
        if(isStack + isQueue + isPriorityQueue == 0)
			puts("impossible");
		else if(isStack + isQueue + isPriorityQueue >= 2)
			puts("not sure");
		else if(isStack)
			puts("stack");
		else if(isQueue)
			puts("queue");
		else if(isPriorityQueue)
			puts("priority queue");
		free(stack);
		free(queue);
		free(priorityQueue);
    }
    return 0;
}
