import java.io.*;

public class Main {
    static short[] primes = {2, 3, 5, 7, 11, 13};
	public static void main(String[] args) throws IOException {
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
			int ans = L, count = factorCount(L);
			L += (L + 1) % 2 + 1;
			while(L % 6 != 0 && L <= U) {
    		    int temp = factorCount(L);
    			if(count < temp) {
    				count = temp;
    				ans = L;
    			}
    			L += 2;
    		}
    		while(L % 12 != 0 && L <= U) {
    		    int temp = factorCount(L);
    			if(count < temp) {
    				count = temp;
    				ans = L;
    			}
    			L += 6;
    		}
    		while(L <= U) {
    		    int temp = factorCount(L);
    			if(count < temp) {
    				count = temp;
    				ans = L;
    			}
    			L += 12;
    		}
    		output.append(ans + " has a maximum of " + count + " divisors.\n");
		}
	    System.out.print(output);
	}
    
    static int factorCount(int n) {
        int result = 1, i = 0;
    	while(i < 6 && n > 1) {
    	    int currPow = 0;
    	    while(n % primes[i] == 0) {
    	        ++currPow;
    	        n /= primes[i];
    	    }
    	    result *= currPow + 1;
    	    ++i;
    	}
    	if(n > 1)
    	    result *= 2;
    	return result;
    }
}
