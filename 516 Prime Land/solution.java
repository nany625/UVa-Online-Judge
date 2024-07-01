import java.util.*;

public class Main {
    static short[] primes = new short[3507];
    static int count = 1;
	public static void main(String[] args) {
		primes[0] = 2;
		for(short i = 3; count < primes.length; i += 2) {
    	    if(isPrime(i))
    	        primes[count++] = i;
    	}
    	Scanner sc = new Scanner(System.in);
    	String line;
    	while(!(line = sc.nextLine()).equals("0")) {
    	    int x = 1;
    	    String[] tokens = line.split("\\s+");
    	    for(int i = 0; i < tokens.length; i += 2) 
    	        x *= Math.pow(Integer.parseInt(tokens[i]), Integer.parseInt(tokens[i + 1]));
    	    --x;
    	    int pos = binarySearch(primes, x);
    	    boolean space = false;
    	    while(pos >= 0 && x > 1) {
    	        if(x % primes[pos] == 0) {
    	            if(space)
    	                System.out.print(" ");
    	            int e = 0;
    	            do {
    	                ++e;
    	                x /= primes[pos];
    	            } while(x % primes[pos] == 0);
    	            System.out.print(primes[pos] + " " + e);
    	            space = true;
    	        }
    	        --pos;
    	    }
    	    System.out.println();
    	}
		sc.close();
	}
	
	static boolean isPrime(short n) {
	    short limit = (short)Math.sqrt(n);
	    for(int i = 1; i < count && primes[i] <= limit; ++i) {
	        if(n % primes[i] == 0)
	            return false;
	    }
	    return true;
	}
	
	static int binarySearch(short[] array, int key) {
        int left = 0, right = array.length - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(array[mid] == key)
                return mid;
            if(array[mid] < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left - 1;
    }
}
