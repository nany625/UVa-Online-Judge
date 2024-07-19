#include <stdio.h>
#include <stdbool.h>

int main() {
    int lumberjacks[10], N;
    scanf("%d", &N);
    puts("Lumberjacks:");
	while(N--) {
	    for(int i = 0; i < 10; ++i)
	        scanf("%d", &lumberjacks[i]);
	    bool ordered = true;
	    for(int i = 0; i < 8 && ordered; ++i)
	        ordered = lumberjacks[i] > lumberjacks[i + 1] == lumberjacks[i + 1] > lumberjacks[i + 2];
	    puts(ordered ? "Ordered" : "Unordered");
	}
    return 0;
}
