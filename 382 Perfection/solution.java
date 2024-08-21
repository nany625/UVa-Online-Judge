import java.io.*;

public class Main {
    static short[] primes = {
        2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 
        31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 
        73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 
        127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 
        179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 
        233, 239, 241
    };
	public static void main(String[] args) throws IOException {
    	StreamTokenizer st = new StreamTokenizer(System.in);
    	int n;
    	StringBuilder output = new StringBuilder("PERFECTION OUTPUT\n");
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
    	    if(n > 6 && n % 6 == 0)
    	        output.append(String.format("%5d  ABUNDANT\n", n));
    	    else {
                long sum = sumOfDivisors(n) - n;
        		if(sum < n)
        			output.append(String.format("%5d  DEFICIENT\n", n));
        		else if(sum == n)
            		output.append(String.format("%5d  PERFECT\n", n));
            	else
            		output.append(String.format("%5d  ABUNDANT\n", n));
    	    }
    	}
	    System.out.println(output + "END OF OUTPUT");
	}
	
	static int sumOfDivisors(int n) {
        int sum = 1, limit = (int)Math.sqrt(n);
        for(int i = 0; i < 53 && primes[i] <= limit; ++i) {
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
