import java.io.*;
import java.util.*;

public class Main {
    static short MAX_NUM = 32693;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
    static ArrayList<Short> primes = new ArrayList<>();
	public static void main(String[] args) throws IOException {
		primes.add((short)2);
		for(short i = 3; i <= MAX_NUM; ++i) {
	        if(!isComposite[i]) {
    	        primes.add(i);
                if(i <= 180) {
                    for(int j = i * i; j <= MAX_NUM; j += i << 1)
                        isComposite[j] = true;
                }
    	    }
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
}

class Factor {
    short p;
    int e;
    Factor(short p) {
        this.p = p;
        this.e = 0;
    }
}
