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
        int cases = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(cases-- > 0) {
            st.nextToken();
            int n = (int)st.nval;
            boolean found = false;
    	    do {
    	        ++n;
    		    if((n & 1) == 1 && n <= MAX_NUM && !isComposite[n >> 1])
    		        continue;
    	        found = sumOfFactorDigits(n) == sumOfDigits(n);
    		} while(!found);
    		output.append(n).append('\n');
        }
        System.out.print(output);
	}
	
	static void eulerSieve() {
	    primes.add((short)2);
        for(short n = 3; n <= MAX_NUM; n += 2) {
            if(!isComposite[n >> 1])
                primes.add(n);
            for(int i = 1, temp; (temp = primes.get(i) * n) <= MAX_NUM; ++i) {
                isComposite[temp >> 1] = true;
                if(n % primes.get(i) == 0)
                    break;
            }
        }
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
	    int result = 0, limit = (int)Math.sqrt(n), temp = n;
	    for(int i = 0; i < primes.size() && primes.get(i) <= limit; ++i) {
    	    if(n % primes.get(i) == 0) {
    	        int tempSum = sumOfDigits(primes.get(i));
    	        do {
    	            result += tempSum;
    	            n /= primes.get(i);
    	        } while(n % primes.get(i) == 0);
    	        limit = (int)Math.sqrt(n);
    	    }
    	}
    	if(temp == n)
	        return -1;
	    if(n > 1)
	        result += sumOfDigits(n);
	    return result;
	}
}
