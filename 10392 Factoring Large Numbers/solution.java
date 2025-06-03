import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 1000000;
    static boolean[] isComposite = new boolean[(MAX_NUM >> 1) + 1];
	static ArrayList<Integer> primes = new ArrayList<>();
	public static void main(String[] args) throws IOException {
	    eulerSieve();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		long n;
		StringBuilder output = new StringBuilder();
		while((n = Long.parseLong(br.readLine())) >= 0) {
    		int limit = (int)Math.sqrt(n);
    		for(int i = 0; i < primes.size() && primes.get(i) <= limit; ++i) {
                if(n % primes.get(i) == 0) {
                    do {
                        output.append("    ").append(primes.get(i)).append('\n');
                        n /= primes.get(i);
                    } while(n % primes.get(i) == 0);
                    limit = (int)Math.sqrt(n);
                }
            }
            if(n > 1)
                output.append("    ").append(n).append('\n');
            output.append('\n');
		}
		System.out.print(output);
	}
	
	static void eulerSieve() {
	    primes.add(2);
        for(int n = 3; n <= MAX_NUM; n += 2) {
            if(!isComposite[n >> 1])
                primes.add(n);
            for(int i = 1, temp; (temp = primes.get(i) * n) <= MAX_NUM; ++i) {
                isComposite[temp >> 1] = true;
                if(n % primes.get(i) == 0)
                    break;
            }
        }
    }
}
