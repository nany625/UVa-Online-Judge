import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 999999;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
    static ArrayList<Long> almostPrimes = new ArrayList<>();
	public static void main(String[] args) throws IOException {
	    appendAlmostPrimes(2);
	    for(int i = 3; i <= MAX_NUM; i += 2) {
	        if(!isComposite[i]) {
	            appendAlmostPrimes(i);
	            if(i <= 999) {
	                for(int j = i * i; j <= MAX_NUM; j += i << 1)
	                    isComposite[j] = true;
	            }
	        }
	    }
	    Collections.sort(almostPrimes);
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
        	int posLow = binarySearch(low), posHigh = binarySearch(high);
        	output.append(posHigh - posLow + (posHigh < almostPrimes.size() && almostPrimes.get(posHigh) == high ? 1 : 0)).append('\n');
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
    
	static int binarySearch(long key) {
	    int left = 0, right = almostPrimes.size() - 1;
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
