#include <stdio.h>

int fib[] = {
	0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 
    55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 
    6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 
    832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986
};

int binarySearch(int key) {
    int left = 0, right = 39;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(fib[mid] == key)
            return mid;
        if(fib[mid] < key)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return left - 1;
}

int main() {
	int N;
	scanf("%d", &N);
	while(N--) {
	    int number;
	    scanf("%d", &number);
	    printf("%d = ", number);
	    if(number == 1) {
	        puts("1 (fib)");
	        continue;
	    }
	    for(int i = binarySearch(number); i >= 2; --i) {
	        printf("%d", number / fib[i]);
	        number %= fib[i];
	    }
	    puts(" (fib)");
	}
	return 0;
}
