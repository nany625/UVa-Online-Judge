import java.io.*;

public class Main {
    static short[] primes = new short[3512], pairs = new short[16382];
    static int count = 1;
	public static void main(String[] args) throws IOException {
    	primes[0] = 2;
    	for(short i = 3; count < primes.length; i += 2) {
            if(isPrime(i))
                primes[count++] = i;
        }
        pairs[0] = 1;
        for(int i = 1; i < 3512; ++i) {
            for(int j = i; j < 3512; ++j) {
                int sum = primes[i] + primes[j];
                if(sum < 32768)
                    ++pairs[sum / 2 - 2];
            }
        }
        StreamTokenizer st = new StreamTokenizer(System.in);
        int n;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0)
    		output.append(pairs[n / 2 - 2]).append('\n');
	    System.out.print(output);
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
