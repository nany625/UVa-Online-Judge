import java.io.*;
import java.util.*;

public class Main {
    static short MAX_NUM = 31607;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
    static ArrayList<Short> primes = new ArrayList<>();
	public static void main(String[] args) throws IOException {
        primes.add((short)2);
    	for(short i = 3; i <= MAX_NUM; i += 2) {
    		if(!isComposite[i]) {
    		    primes.add(i);
    		    if(i <= 177) {
    	            for(int j = i * i; j <= MAX_NUM; j += i)
    	                isComposite[j] = true;
    	        }
    		}
    	}
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
    
    static int factorCount(int n) {
        int result = 1, i = 0;
    	while(i < primes.size() && n > 1) {
    	    int currPow = 0;
    	    while(n % primes.get(i) == 0) {
    	        ++currPow;
    	        n /= primes.get(i);
    	    }
    	    result *= currPow + 1;
    	    ++i;
    	}
    	if(n > 1)
    	    result <<= 1;
    	return result;
    }
}
