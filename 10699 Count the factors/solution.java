import java.io.*;
import java.util.*;

public class Main {
    static short MAX_NUM = 1000;
    static boolean[] isComposite = new boolean[(MAX_NUM >> 1) + 1];
    static ArrayList<Short> primes = new ArrayList<>();
	public static void main (String[] args) throws IOException {
		eratosthenesSieve();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int num;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (num = (int)st.nval) != 0) {
		    output.append(num).append(" : ");
		    short limit = (short)Math.sqrt(num);
		    int count = 0;
		    for(int i = 0; i < primes.size() && primes.get(i) <= limit; ++i) {
		        if(num % primes.get(i) == 0) {
                    ++count;
                    do {
                        num /= primes.get(i);
                    } while(num % primes.get(i) == 0);
                    limit = (short)Math.sqrt(num);
		        }
		    }
		    output.append(count + (num > 1 ? 1 : 0)).append('\n');
		}
		System.out.print(output);
	}
	
	static void eratosthenesSieve() {
	    primes.add((short)2);
        for(short n = 3; n <= MAX_NUM; n += 2) {
            if(!isComposite[n >> 1]) {
                primes.add(n);
                if(n <= 31) {
                    for(int i = n * n; i <= MAX_NUM; i += n << 1)
                        isComposite[i >> 1] = true;
                }
            }
        }
    }
}
