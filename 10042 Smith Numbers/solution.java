import java.io.*;
import java.util.*;

public class Main {
    static short MAX_NUM = 31607;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
    static ArrayList<Short> primes = new ArrayList<>();
	public static void main(String[] args) throws IOException {
    	for(short i = 2; i <= MAX_NUM; ++i) {
    	    if(!isComposite[i]) {
    	        primes.add(i);
        	    if(i <= 177) {
        	        for(int j = i * i; j <= MAX_NUM; j += i)
        	            isComposite[j] = true;
        	    }
    	    }
    	}
    	int size = primes.size();
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
    		    if(n <= MAX_NUM && !isComposite[n])
    		        continue;
    	        found = sumOfFactorDigits(size, n) == sumOfDigits(n);
    		} while(!found);
    		output.append(n).append('\n');
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
	
	static int sumOfFactorDigits(int size, int n) {
	    int result = 0, limit = (int)Math.sqrt(n);
	    boolean isPrime = true;
	    for(int i = 0; i < size && primes.get(i) <= limit; ++i) {
    	    if(n % primes.get(i) == 0) {
                isPrime = false;
    	        int tempSum = sumOfDigits(primes.get(i));
    	        do {
    	            result += tempSum;
    	            n /= primes.get(i);
    	        } while(n % primes.get(i) == 0);
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
