#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	short source, time, duration, target;
} Request;

typedef struct {
	short extention;
} Call;

int main() {
	int N;
	scanf("%d", &N);
	puts("CALL FORWARDING OUTPUT");
	for(int i = 1; i <= N; ++i) {
		printf("SYSTEM %d\n", i);
		Request *requests = NULL;
		int requestCount = 0;
		short source;
		while(scanf("%hd", &source) && source != 0) {
			requests = (Request*)realloc(requests, (requestCount + 1) * sizeof(Request));
			requests[requestCount].source = source;
			scanf("%hd %hd %hd", &requests[requestCount].time, &requests[requestCount].duration, &requests[requestCount].target);
			++requestCount;
		}
		short time;
		while(scanf("%hd", &time) && time != 9000) {
		    Call *calls = NULL;
		    calls = (Call*)realloc(calls, sizeof(Call));
			scanf("%hd", &calls[0].extention);
			bool deadEnd = false;
			int j = 0, callCount = 1;
			while(j < requestCount && !deadEnd) {
				if(requests[j].source == calls[callCount - 1].extention) {
					if(time >= requests[j].time && time <= requests[j].time + requests[j].duration) {
						int k = 0;
						while(k < callCount && calls[k].extention != requests[j].target)
							++k;
						if(k < callCount)
							deadEnd = true;
						else {
							calls = (Call*)realloc(calls, (callCount + 1) * sizeof(Call));
							calls[callCount++].extention = requests[j].target;
							j = 0;
						}
					} else
						++j;
				} else
                    ++j;
			}
			printf("AT %04hd CALL TO %04hd RINGS %04hd\n", time, calls[0].extention, deadEnd ? 9999 : calls[callCount - 1].extention);
			free(calls);
		}
		free(requests);
	}
	puts("END OF OUTPUT");
	return 0;
}
