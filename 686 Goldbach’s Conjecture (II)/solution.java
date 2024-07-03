import java.io.*;

public class Main {
    static boolean[] map = new boolean[32768];
    static short[] primes = new short[3512];
    static int count = 1;
	public static void main(String[] args) throws IOException {
        map[2] = true;
    	primes[0] = 2;
    	for(short i = 3; count < primes.length; i += 2) {
            if(isPrime(i)) {
                map[i] = true;
                primes[count++] = i;
            }
        }
        StreamTokenizer st = new StreamTokenizer(System.in);
        int n;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
    	    count = map[n - 2] ? 1 : 0;
    		int limit = n / 2;
    		for(int i = 1; primes[i] <= limit; ++i) {
    			if(map[n - primes[i]])
    				++count;
    		}
    		output.append(count + "\n");
        }
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
