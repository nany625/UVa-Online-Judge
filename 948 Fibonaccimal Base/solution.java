import java.io.*;

public class Main {
    static int[] fib = {
    	0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 
        55, 89, 144, 233, 377, 610, 987, 1597, 2584, 4181, 
        6765, 10946, 17711, 28657, 46368, 75025, 121393, 196418, 317811, 514229, 
        832040, 1346269, 2178309, 3524578, 5702887, 9227465, 14930352, 24157817, 39088169, 63245986
    };
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int N = (int)st.nval;
        StringBuilder output = new StringBuilder();
    	while(N-- > 0) {
    	    st.nextToken();
    	    int number = (int)st.nval;
    	    output.append(number).append(" = ");
    	    if(number == 1) {
    	        output.append("1 (fib)\n");
    	        continue;
    	    }
    	    for(int i = binarySearch(number); i >= 2; --i) {
    	        output.append(number / fib[i]);
    	        number %= fib[i];
    	    }
    	    output.append(" (fib)\n");
    	}
        System.out.print(output);
	}
	
	static int binarySearch(int key) {
        int left = 0, right = 39;
        while(left <= right) {
            int mid = left + ((right - left) >> 1);
            if(fib[mid] == key)
                return mid;
            if(fib[mid] < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left - 1;
    }
}
