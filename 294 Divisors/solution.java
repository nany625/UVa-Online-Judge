import java.io.*;

public class Main {
    static short[] primes = new short[3401];
    static int count = 1;
	public static void main(String[] args) throws IOException {
	    primes[0] = 2;
        for(short i = 3; count < 3401; i += 2) {
            if(isPrime(i))
                primes[count++] = i;
        }
        StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int N = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(N-- > 0) {
            st.nextToken();
    		int L = (int)st.nval;
    		st.nextToken();
			int U = (int)st.nval;
			output.append("Between " + L +  " and " + U + ", ");
			int ans = L;
			count = factorCount(L);
			L += L % 2;
			while(L % 6 != 0 && L <= U) {
    		    int temp = factorCount(L);
    			if(count < temp) {
    				count = temp;
    				ans = L;
    			}
    			L += 2;
    		}
    		for(int i = L; i <= U; i += 6) {
    			int temp = factorCount(i);
    			if(count < temp) {
    				count = temp;
    				ans = i;
    			}
        	} 
    		output.append(ans + " has a maximum of " + count + " divisors.\n");
		}
	    System.out.print(output);
	}
	
	static boolean isPrime(short n) {
        short limit = (short)Math.sqrt(n);
        for(int i = 1; i < count && primes[i] <= limit; ++i) {
            if(n % primes[i] == 0)
                return false;
        }
        return true;
    }
    
    static int factorCount(int n) {
        int result = 1, i = 0;
    	while(i < 3401 && n > 1) {
    	    int currPow = 0;
    	    while(n % primes[i] == 0) {
    	        ++currPow;
    	        n /= primes[i];
    	    }
    	    result *= currPow + 1;
    	    ++i;
    	}
    	return result;
    }
}
