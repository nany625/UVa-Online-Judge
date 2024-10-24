import java.io.*;

public class Main {
    static short[] primes = new short[169], pos = new short[1000];
    static int count = 2;
	public static void main(String[] args) throws IOException {
        primes[0] = pos[0] = 1;
	    primes[1] = pos[1] = 2;
	    for(short i = 3; i <= 1000; ++i) {
	        pos[i - 1] = pos[i - 2];
	        if((i & 1) == 1 && count < primes.length) {
	            if(isPrime(i))
	                ++pos[(primes[count++] = i) - 1];
	        }
	    }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int N = (int)st.nval;
            st.nextToken();
            int C = (int)st.nval;
            output.append(N).append(' ').append(C).append(':');
            if((pos[N - 1] & 1) == 0 && C << 1 < pos[N - 1])
        		output.append(printPrimes((pos[N - 1] >> 1) - C, (pos[N - 1] >> 1) + C - 1));
        	else if((pos[N - 1] & 1) == 1 && (C << 1) - 1 < pos[N - 1])
        		output.append(printPrimes((pos[N - 1] + 1 >> 1) - C, (pos[N - 1] - 3 >> 1) + C));
        	else
        		output.append(printPrimes(0, pos[N - 1] - 1));
    	    output.append("\n\n");
        }
        System.out.print(output);
	}
	
	static boolean isPrime(short n) {
	    short limit = (short)Math.sqrt(n);
        for(int i = 2; i < count && primes[i] <= limit; ++i) {
            if(n % primes[i] == 0)
                return false;
        }
        return true;
    }
    
    static StringBuilder printPrimes(int first, int last) {
        StringBuilder ans = new StringBuilder();
    	for(int i = first; i <= last; ++i)
    		ans.append(' ').append(primes[i]);
    	return ans;
    }
}
