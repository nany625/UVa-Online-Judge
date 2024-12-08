import java.io.*;
import java.util.*;

public class Main {
    static short MAX_NUM = 32693;
    static boolean[] isComposite = new boolean[(MAX_NUM >> 1) + 1];
    static ArrayList<Short> primes = new ArrayList<>();
	public static void main(String[] args) throws IOException {
		eulerSieve();
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
    	        if(x % primes.get(i) == 0) {
    	            factors.add(new Factor(primes.get(i)));
    	            do {
    	                ++factors.get(factors.size() - 1).e;
    	                x /= primes.get(i);
    	            } while(x % primes.get(i) == 0);
    	        }
    	    }
    	    for(int i = factors.size() - 1; i > 0; --i)
    	        output.append(factors.get(i).p).append(' ').append(factors.get(i).e).append(' ');
    	    output.append(factors.get(0).p).append(' ').append(factors.get(0).e).append('\n');
    	}
	    System.out.print(output);
	}
	
	static void eulerSieve() {
	    primes.add((short)2);
        for(short n = 3; n <= MAX_NUM; n += 2) {
            if(!isComposite[n >> 1])
                primes.add(n);
            for(int i = 1, temp; i < primes.size() && (temp = primes.get(i) * n) <= MAX_NUM; ++i) {
                isComposite[temp >> 1] = true;
                if(n % primes.get(i) == 0)
                    break;
            }
        }
    }
}

class Factor {
    short p;
    int e;
    Factor(short p) {
        this.p = p;
        this.e = 0;
    }
}
