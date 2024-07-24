import java.io.*;

public class Main {
    static boolean[] isComposite = new boolean[32694];
    static short[] primes = new short[3507];
    static int count = 0;
	public static void main(String[] args) throws IOException {
		for(short i = 2; i <= 32693; ++i) {
    		if(!isComposite[i]) {
    			primes[count++] = i;
    			if(i <= 180) {
    				for(int j = i * i; j <= 32693; j += i)
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
    	    int pos = --x >= 32693 ? 3506 : binarySearch(x);
    	    boolean space = false;
    	    while(x > 1) {
    	        if(x % primes[pos] == 0) {
    	            if(space)
    	                output.append(" ");
    	            int e = 0;
    	            do {
    	                ++e;
    	                x /= primes[pos];
    	            } while(x % primes[pos] == 0);
    	            output.append(primes[pos] + " " + e);
    	            space = true;
    	        }
    	        --pos;
    	    }
    	    output.append("\n");
    	}
	    System.out.print(output);
	}
	
	static int binarySearch(int key) {
        int left = 0, right = 3506;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(primes[mid] == key)
                return mid;
            if(primes[mid] < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        right = left - 1;
        left = 0;
        key /= 2;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(primes[mid] == key)
                return mid;
            if(primes[mid] < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left - 1;
    }
}
