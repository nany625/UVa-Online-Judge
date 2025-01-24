import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 31622;
    static boolean[] isComposite = new boolean[(MAX_NUM >> 1) + 1];
	static ArrayList<Short> primes = new ArrayList<>();
	public static void main(String[] args) throws IOException {
	    eulerSieve();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int n;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0)
			output.append(eulerTotient(n)).append('\n');
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
    
    static int eulerTotient(int n) {
        int ans = n, limit = (int)Math.sqrt(n);
        for(int i = 0; i < primes.size() && primes.get(i) <= limit; ++i) {
            if(n % primes.get(i) == 0) {
                ans -= ans / primes.get(i);
                do {
                    n /= primes.get(i);
                } while(n % primes.get(i) == 0);
                limit = (int)Math.sqrt(n);
            }
        }
        if(n > 1)
            ans -= ans / n;
        return ans;
    }
}
