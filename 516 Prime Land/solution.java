import java.io.*;
import java.util.*;

public class Main {
    static short[] primes = new short[3507];
    static int count = 1;
	public static void main(String[] args) throws IOException {
		primes[0] = 2;
		for(short i = 3; count < 3507; i += 2) {
    	    if(isPrime(i))
    	        primes[count++] = i;
    	}
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    	String line;
    	StringBuilder output = new StringBuilder();
    	while((line = br.readLine()).charAt(0) != '0') {
    	    int x = 1;
    	    String[] tokens = line.split("\\s+");
    	    for(int i = 0; i < tokens.length; i += 2) 
    	        x *= Math.pow(Integer.parseInt(tokens[i]), Integer.parseInt(tokens[i + 1]));
    	    --x;
    	    ArrayList<Factor> factors = new ArrayList<>();
    	    for(int i = 0; x > 1; ++i) {
    	        if(x % primes[i] == 0) {
    	            int e = 0;
    	            do {
    	                ++e;
    	                x /= primes[i];
    	            } while(x % primes[i] == 0);
    	            factors.add(new Factor(primes[i], e));
    	        }
    	    }
    	    for(int i = factors.size() - 1; i >= 0; --i) {
    	        output.append(factors.get(i).p).append(' ').append(factors.get(i).e);
    	        if(i > 0)
    	            output.append(' ');
    	    }
    	    output.append('\n');
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

class Factor {
    short p;
    int e;
    Factor(short p, int e) {
        this.p = p;
        this.e = e;
    }
}
