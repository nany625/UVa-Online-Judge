import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 9999999;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
    static ArrayList<Integer> primes = new ArrayList<>();
    static int[] ans = new int[MAX_NUM + 1];
	public static void main(String[] args) throws IOException {
	    eulerSieve();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		long n;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (long)st.nval) != 1)
            output.append(n <= MAX_NUM ? ans[(int)n] : pfCount(n)).append('\n');
		System.out.print(output);
	}
	
	static void eulerSieve() {
		for(int n = 2; n <= MAX_NUM; ++n) {
			if(!isComposite[n]) {
				primes.add(n);
				ans[n] = 1;
			}
			for(int i = 0, temp; (temp = primes.get(i) * n) <= MAX_NUM; ++i) {
				isComposite[temp] = true;
				ans[temp] = ans[primes.get(i)] + ans[n];
				if(n % primes.get(i) == 0)
					break;
			}
		}
	}
	
	static int pfCount(long n) {
        int result = 0, limit = (int)Math.sqrt(n);
        for(int i = 0; i < primes.size() && primes.get(i) <= limit; ++i) {
            if(n % primes.get(i) == 0) {
                do {
                    ++result;
                    n /= primes.get(i);
                } while(n % primes.get(i) == 0);
                limit = (int)Math.sqrt(n);
            }
        }
        return result + (n > 1 ? 1 : 0);
    }
}
