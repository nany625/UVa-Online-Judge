import java.io.*;

public class Main {
    static short[] primes = new short[1230], ppCount = new short[10001];
	static int primesCount = 1;
	public static void main(String[] args) throws IOException {
	    primes[0] = 2;
    	for(short i = 3; primesCount < primes.length; i += 2) {
    		if(isPrime(i))
    			primes[primesCount++] = i;
    	}
    	for(short i = 0; i < 40; ++i)
    		ppCount[i] = (short)(i + 1);
    	ppCount[40] = ppCount[41] = 40;
    	for(int i = 42; i <= 10000; ++i) {
    	    ppCount[i] = ppCount[i - 1];
    		if(i % 41 == 0 || (i + 1) % 41 == 0)
    			continue;
    		if(isPrime(i * i + i + 41))
    			++ppCount[i];
    	}
	    StreamTokenizer st = new StreamTokenizer(System.in);
	    StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int a = (int)st.nval;
            st.nextToken();
            int b = (int)st.nval;
    	    output.append(String.format("%.2f\n", 100.0 * (ppCount[b] - ppCount[a] + (a == 0 || ppCount[a] > ppCount[a - 1] ? 1 : 0)) / (b - a + 1) + 0.0000001));
        }
	    System.out.print(output);
	}
	
	static boolean isPrime(int n) {
	    short limit = (short)Math.sqrt(n);
		for(int i = 1; i < primesCount && primes[i] <= limit; ++i) {
			if(n % primes[i] == 0)
				return false;
		}
		return true;
	}
}
