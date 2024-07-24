import java.io.*;

public class Main {
    static boolean[] isComposite = new boolean[31608];
    static short[] primes = new short[3401];
    static int count = 0;
	public static void main(String[] args) throws IOException {
    	for(short i = 2; i <= 31607; ++i) {
    	    if(!isComposite[i]) {
    	        primes[count++] = i;
        	    if(i <= 177) {
        	        for(int j = i * i; j <= 31607; j += i)
        	            isComposite[j] = true;
        	    }
    	    }
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
    		    if(n <= 31607 && !isComposite[n])
    		        continue;
    	        found = sumOfFactorDigits(n) == sumOfDigits(n);
    		} while(!found);
    		output.append(n + "\n");
        }
        System.out.print(output);
	}
	
	static int sumOfDigits(int n) {
	    int result = 0;
	    while(n > 0) {
	        result += n % 10;
	        n /= 10;
	    }
	    return result;
	}
	
	static int sumOfFactorDigits(int n) {
	    int result = 0, limit = (int)Math.sqrt(n);
	    boolean isPrime = true;
	    for(int i = 0; i < 3401 && primes[i] <= limit; ++i) {
    	    if(n % primes[i] == 0) {
                isPrime = false;
    	        int tempSum = sumOfDigits(primes[i]);
    	        do {
    	            result += tempSum;
    	            n /= primes[i];
    	        } while(n % primes[i] == 0);
    	        limit = (int)Math.sqrt(n);
    	    }
    	}
    	if(isPrime)
	        return -1;
	    if(n > 1)
	        result += sumOfDigits(n);
	    return result;
	}
}
