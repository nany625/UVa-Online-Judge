import java.io.*;

public class Main {
    static short[] primes = new short[3401];
    static int count = 1;
	public static void main(String[] args) {
	    try {
	        primes[0] = 2;
            for(short i = 3; count < primes.length; i += 2) {
                if(isPrime(i))
                    primes[count++] = i;
            }
            StreamTokenizer st = new StreamTokenizer(System.in);
            st.nextToken();
            int N = (int)st.nval;
            while(N-- > 0) {
                st.nextToken();
    			int L = (int)st.nval;
    			st.nextToken();
    			int U = (int)st.nval, maxCount = 0, ans = L;
    			for(int i = L; i <= U; ++i) {
        			int factorCount = 1, j = 0, temp = i;
        			while(j < primes.length && temp > 1) {
        			    int currPow = 0;
        			    while(temp % primes[j] == 0) {
        			        ++currPow;
        			        temp /= primes[j];
        			    }
        			    factorCount *= currPow + 1;
        			    ++j;
        			}
        			if(maxCount < factorCount) {
        				maxCount = factorCount;
        				ans = i;
        			}
        		}
    			System.out.println("Between " + L + " and " + U + ", " + ans + " has a maximum of " + maxCount + " divisors.");
    		}
	    } catch(IOException e) {}
	}
	
	static boolean isPrime(short n) {
        short limit = (short)Math.sqrt(n);
        for(int i = 1; i < count && primes[i] <= limit; ++i) {
            if(n % primes[i] == 0)
                return false;
        }
        return true;
    }
}
