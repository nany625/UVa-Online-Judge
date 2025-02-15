#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int time1, time2;    
} Appointment;

int compare(const void *a, const void *b) {
    return ((Appointment*)a)->time1 > ((Appointment*)b)->time1;
}

int main() {
	int day = 0, s;
    char *buffer = NULL;
	size_t bufsize = 0;
	while(scanf("%d", &s) == 1) {
	    Appointment appointments[s + 2];
	    appointments[0] = (Appointment){0, 600};
	    appointments[s + 1].time1 = 1080;
	    int hh, mm;
	    for(int i = 1; i < s + 1; ++i) {
	        scanf("%d %*c %d", &hh, &mm);
	        appointments[i].time1 = 60 * hh + mm;
	        scanf("%d %*c %d", &hh, &mm);
	        appointments[i].time2 = 60 * hh + mm;
	        getline(&buffer, &bufsize, stdin);
	    }
	    qsort(appointments, s + 2, sizeof(Appointment), compare);
	    int longest = appointments[1].time1 - 600, start = 600;
	    for(int i = 2; i < s + 2; ++i) {
	        if(longest < appointments[i].time1 - appointments[i - 1].time2) {
	            longest = appointments[i].time1 - appointments[i - 1].time2;
	            start = appointments[i - 1].time2;
	        }
	    }
	    printf("Day #%d: the longest nap starts at %02d:%02d and will last for ", ++day, start / 60, start % 60);
	    if(longest / 60)
	        printf("%d hours and %d minutes.\n", longest / 60, longest % 60);
	    else
	        printf("%d minutes.\n", longest);
	}
    free(buffer);
	return 0;
}
