import java.io.*;
import java.util.*;

public class Main {
    static boolean[] isComposite = new boolean[1000000];
    static ArrayList<Long> almostPrimes = new ArrayList<>();
	public static void main(String[] args) throws IOException {
	    appendAlmostPrimes(2);
	    for(int i = 3; i <= 999999; i += 2) {
	        if(!isComposite[i]) {
	            appendAlmostPrimes(i);
	            if(i <= 999) {
	                for(int j = i * i; j <= 999999; j += i)
	                    isComposite[j] = true;
	            }
	        }
	    }
	    Collections.sort(almostPrimes);
	    int size = almostPrimes.size();
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	StreamTokenizer st = new StreamTokenizer(br);
    	st.nextToken();
    	int N = (int)st.nval;
    	StringBuilder output = new StringBuilder();
    	while(N-- > 0) {
	        st.nextToken();
        	long low = (long)st.nval;
        	st.nextToken();
        	long high = (long)st.nval;
        	int posLow = binarySearch(size, low), posHigh = binarySearch(size, high);
        	output.append(posHigh - posLow + (posHigh < size && almostPrimes.get(posHigh) == high ? 1 : 0)).append('\n');
    	}
	    System.out.print(output);
	}
	
	static void appendAlmostPrimes(int i) {
        long p = (long)i * i;
        while(p < 1000000000000L) {
    	    almostPrimes.add(p);
	        p *= i;
        }
    }
    
	static int binarySearch(int size, long key) {
	    int left = 0, right = size - 1;
	    while(left <= right) {
	        int mid = left + (right - left >> 1);
	        if(almostPrimes.get(mid) == key)
	            return mid;
	        if(almostPrimes.get(mid) < key)
	            left = mid + 1;
	        else
	            right = mid - 1;
	    }
	    return left;
	}
}
