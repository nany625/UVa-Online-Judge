import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 1000000;
    static boolean[] isComposite = new boolean[MAX_NUM + 1]; 
    static ArrayList<Integer> primes = new ArrayList<>();
	public static void main(String[] args) throws IOException {
        eulerSieve();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int t = (int)st.nval;
        StringBuilder output = new StringBuilder();
		while(t-- > 0) {
    		st.nextToken();
            long n = (long)st.nval;
            if(n > 6 && n % 6 == 0)
    	        output.append("abundant\n");
    	    else {
                long sum = sumOfDivisors(n) - n;
        		if(sum < n)
        			output.append("deficient\n");
        		else if(sum == n)
            		output.append("perfect\n");
            	else
            		output.append("abundant\n");
    	    }
    	}
        System.out.print(output);
	}
	
	static void eulerSieve() {
        for(int n = 2; n <= MAX_NUM; ++n) {
            if(!isComposite[n])
                primes.add(n);
            for(int i = 0, temp; i < primes.size() && (temp = primes.get(i) * n) <= MAX_NUM; ++i) {
                isComposite[temp] = true;
                if(n % primes.get(i) == 0)
                    break;
            }
        }
    }
	
	static long sumOfDivisors(long n) {
        long sum = 1, limit = (long)Math.sqrt(n);
        for(int i = 0; i < primes.size() && primes.get(i) <= limit; ++i) {
            if(n % primes.get(i) == 0) {
                long tempSum = 1, term = 1;
                do {
                    tempSum += term *= primes.get(i);
                    n /= primes.get(i);
                } while(n % primes.get(i) == 0);
                sum *= tempSum;
                limit = (long)Math.sqrt(n);
            }
        }
        if(n > 1)
            sum *= (1 + n);
        return sum;
    }
}
