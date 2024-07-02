import java.io.*;
import java.util.*;

public class Main {
    static short[] primes = new short[3401];
    static int count = 1;
	public static void main(String[] args) throws IOException {
	    primes[0] = 2;
    	for(short i = 3; count < primes.length; i += 2) {
    		if(isPrime(i) == -1)
    		    primes[count++] = i;
    	}
        StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int cases = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(cases-- > 0) {
            st.nextToken();
            int n = (int)st.nval;
            boolean found = false;
    	    do {
    	        ++n;
    		    if(n <= primes[primes.length - 1]) {
    		        if(Arrays.binarySearch(primes, (short)n) < 0) {
    		            if(sumOfFactorDigits(0, n) == sumOfDigits(n))
    	                    found = true;
    	            }
    	        } else {
    	            int start = isPrime(n);
    	            if(start != -1) {
    	                if(sumOfFactorDigits(start, n) == sumOfDigits(n))
    	                    found = true;
    	            }
    	        }
    		} while(!found);
    		output.append(n + "\n");
        }
        System.out.print(output);
	}
	
	static int isPrime(int n) {
	    int limit = (int)Math.sqrt(n);
    	for(int i = 0; i < count && primes[i] <= limit; ++i) {
    		if(n % primes[i] == 0)
    			return i;
    	}
    	return -1;
	}
	
	static int sumOfDigits(int n) {
	    int result = 0;
	    while(n > 0) {
	        result += n % 10;
	        n /= 10;
	    }
	    return result;
	}
	
	static int sumOfFactorDigits(int start, int n) {
	    int result = 0;
	    while(start < primes.length && n > 1) {
	        if(n % primes[start] == 0) {
	            result += sumOfDigits(primes[start]);
	            n /= primes[start];
	        } else
	            ++start;
	    }
	    if(n > 1)
	        result += sumOfDigits(n);
	    return result;
	}
}
