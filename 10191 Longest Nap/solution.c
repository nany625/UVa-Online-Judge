#include <stdio.h>

typedef struct {
    int time1, time2;    
} Appointment;

void swap(Appointment *a, Appointment *b) {
	Appointment temp = *a;
	*a = *b;
	*b = temp;
}

void InsertionSort(Appointment *array, int size) {
    for(int i = 2; i < size + 1; ++i) {
        int j = i - 1;
        Appointment temp = array[i];
        while(j >= 1 && temp.time1 < array[j].time1) {
            array[j + 1] = array[j];
            --j;
        }
        array[j + 1] = temp;
    }
}

void DualPivotPartition(Appointment *array, int *partitionIndices, int left, int right) {
	if(array[left].time1 > array[right].time1)
		swap(&array[left], &array[right]);
	int low = left + 1, high = right - 1;
	Appointment pivot1 = array[left], pivot2 = array[right];
	for(int i = low; i <= high; ++i) {
		if(array[i].time1 < pivot1.time1)
			swap(&array[low++], &array[i]);
		else if(array[i].time1 > pivot2.time1)
			swap(&array[high--], &array[i--]);
	}
	swap(&array[--low], &array[left]);
	swap(&array[++high], &array[right]);
	partitionIndices[0] = low;
	partitionIndices[1] = high;
}

void DualPivotQuickSort(Appointment *array, int left, int right) {
    if(left < right) {
        int partitionIndices[2];
        DualPivotPartition(array, partitionIndices, left, right);
		DualPivotQuickSort(array, left, partitionIndices[0] - 1);
		DualPivotQuickSort(array, partitionIndices[0] + 1, partitionIndices[1] - 1);
		DualPivotQuickSort(array, partitionIndices[1] + 1, right);
    }
}

int main() {
	int day = 0, s;
	while(scanf("%d", &s) == 1) {
	    Appointment appointments[s + 2];
	    appointments[0].time2 = 600;
	    appointments[s + 1].time1 = 1080;
	    int hh, mm;
	    char appointment[245];
	    for(int i = 1; i < s + 1; ++i) {
	        scanf("%d %*c %d", &hh, &mm);
	        appointments[i].time1 = 60 * hh + mm;
	        scanf("%d %*c %d", &hh, &mm);
	        appointments[i].time2 = 60 * hh + mm;
	        fgets(appointment, sizeof(appointment), stdin);
	    }
	    s <= 47 ? InsertionSort(appointments, s) : DualPivotQuickSort(appointments, 1, s);
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
	return 0;
}
