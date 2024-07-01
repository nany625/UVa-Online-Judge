import java.io.*;

public class Main {
    static String[] firstGrid = new String[6], secondGrid = new String[6];
	public static void main(String[] args) {
	    try {
    	    StreamTokenizer st = new StreamTokenizer(System.in);
            int k;
            while(st.nextToken() == StreamTokenizer.TT_NUMBER && (k = (int)st.nval) != 0) {
                if(isPrime(k))
    		        System.out.println(0);
    		    else {
    		    	k -= (k + 1) % 2;
    	            int i = 0, j = 0;
    	            while(!isPrime(k - i))
    	                i += 2;
    	            do {
    	                j += 2;
    	            } while(!isPrime(k + j));
    	            System.out.println(i + j);
    		    }
            }
	    } catch(IOException e) {}
	}
	
	static boolean isPrime(int n) {
	    if(n <= 3)
            return n > 1;
        if(n % 2 == 0 || n % 3 == 0)
            return false;
        int limit = (int)Math.sqrt(n);
        for(int i = 5; i <= limit; i += 6) {
            if(n % i == 0 || n % (i + 2) == 0)
                return false;
        }
		return true;
	}
}
