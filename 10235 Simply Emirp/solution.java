import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
    	    int N = (int)st.nval;
    	    if(!isPrime(N))
    	        output.append(N).append(" is not prime.\n");
    	    else {
    	        int reverse = 0, temp = N;
                while(temp > 0) {
                    reverse = 10 * reverse + temp % 10;
                    temp /= 10;
                }
                if(reverse != N && isPrime(reverse))
                    output.append(N).append(" is emirp.\n");
    			else
    				output.append(N).append(" is prime.\n");
    	    }
    	}
    	System.out.print(output);
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
