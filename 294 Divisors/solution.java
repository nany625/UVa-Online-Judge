import java.io.*;
import java.util.*;

public class Main {
    static short MAX_NUM = 31622;
    static boolean[] isComposite = new boolean[(MAX_NUM >> 1) + 1];
    static ArrayList<Short> primes = new ArrayList<>();
	public static void main(String[] args) throws IOException {
        eulerSieve();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int N = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(N-- > 0) {
            st.nextToken();
    		int L = (int)st.nval;
    		st.nextToken();
			int U = (int)st.nval;
			output.append("Between ").append(L).append(" and ").append(U).append(", ");
			int ans = L, count = factorCount(L);
			L += ((L + 1) & 1) + 1;
			while(L % 6 != 0 && L <= U) {
    		    int temp = factorCount(L);
    			if(count < temp) {
    				count = temp;
    				ans = L;
    			}
    			L += 2;
    		}
    		while(L <= U) {
    		    int temp = factorCount(L);
    			if(count < temp) {
    				count = temp;
    				ans = L;
    			}
    			L += 6;
    		}
    		output.append(ans).append(" has a maximum of ").append(count).append(" divisors.\n");
		}
	    System.out.print(output);
	}
	
	static void eulerSieve() {
	    primes.add((short)2);
        for(short n = 3; n <= MAX_NUM; n += 2) {
            if(!isComposite[n >> 1])
                primes.add(n);
            for(int i = 1, temp; i < primes.size() && (temp = primes.get(i) * n) <= MAX_NUM; ++i) {
                isComposite[temp >> 1] = true;
                if(n % primes.get(i) == 0)
                    break;
            }
        }
    }
    
    static int factorCount(int n) {
        int result = 1, i = 0;
    	while(i < primes.size() && n > 1) {
    	    int term = 1;
    	    while(n % primes.get(i) == 0) {
    	        ++term;
    	        n /= primes.get(i);
    	    }
    	    result *= term;
    	    ++i;
    	}
    	if(n > 1)
    	    result <<= 1;
    	return result;
    }
}
