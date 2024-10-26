import java.io.*;

public class Main {
    static short[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int t = (int)st.nval;
        StringBuilder output = new StringBuilder();
		while(t-- > 0) {
    		st.nextToken();
            int n = (int)st.nval;
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
	
	static int sumOfDivisors(int n) {
        int sum = 1, limit = (int)Math.sqrt(n);
        for(int i = 0; i < 11 && primes[i] <= limit; ++i) {
            if(n % primes[i] == 0) {
                int tempSum = 1, term = 1;
                do {
                    tempSum += term *= primes[i];
                    n /= primes[i];
                } while(n % primes[i] == 0);
                sum *= tempSum;
                limit = (int)Math.sqrt(n);
            }
        }
        if(n > 1)
            sum *= (1 + n);
        return sum;
    }
}
