import java.io.*;

public class Main {
    static boolean[] isComposite = new boolean[1000001]; 
    static int[] primes = new int[78498];
    static int count = 0;
	public static void main(String[] args) throws IOException {
        for(int i = 2; count < 78498; ++i) {
            if(!isComposite[i]) {
                primes[count++] = i;
                if(i <= 1000) {
                    for(int j = i * i; j <= 1000000; j += i)
                        isComposite[j] = true;
                }
            }
        }
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
	
	static long sumOfDivisors(long n) {
        long sum = 1, limit = (long)Math.sqrt(n);
        for(int i = 0; i < 78498 && primes[i] <= limit; ++i) {
            if(n % primes[i] == 0) {
                long tempSum = 1, term = 1;
                do {
                    tempSum += term *= primes[i];
                    n /= primes[i];
                } while(n % primes[i] == 0);
                sum *= tempSum;
                limit = (long)Math.sqrt(n);
            }
        }
        if(n > 1)
            sum *= (1 + n);
        return sum;
    }
}
