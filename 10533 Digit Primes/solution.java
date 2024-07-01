import java.io.*;

public class Main {
    static int[] primes = new int[78498];
    static short[] dpCount = new short[999999];
    static int primesCount = 1;
	public static void main(String[] args) {
	    try {
	        primes[0] = 2;
    		dpCount[1] = 1;
    		for(int i = 3; i < 1000000; ++i) {
    		    dpCount[i - 1] = dpCount[i - 2];
        	    if(i % 2 == 1 && primesCount < primes.length) {
        	        if(isPrime(i)) {
        	            primes[primesCount++] = i;
        	            if(isPrime(sumOfDigits(i)))
        	                ++dpCount[i - 1];
        	        }
        	    }
    		}
	        StreamTokenizer st = new StreamTokenizer(System.in);
	        st.nextToken();
	        int N = (int)st.nval;
	        while(N-- > 0) {
	            st.nextToken();
    		    int t1 = (int)st.nval;
    		    st.nextToken();
    		    int t2 = (int)st.nval;
    			System.out.println(dpCount[t2 - 1] - dpCount[t1 - 1] + (t1 > 1 && dpCount[t1 - 1] > dpCount[t1 - 2] ? 1 : 0));
    		}
	    } catch(IOException e) {}
	}
	
	static boolean isPrime(int n) {
	    int limit = (int)Math.sqrt(n);
        for(int i = 0; i < primesCount && primes[i] <= limit; ++i) {
            if(n % primes[i] == 0)
                return false;
        }
        return true;
    }
	
	static int sumOfDigits(int n) {
        int result = 0;
        while(n > 0) {
            result += n % 10;
            n /= 10;
        }
        return result;
    }
}
