import java.io.*;
import java.util.*;

public class Main {
    static short MAX_NUM = 10007;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
    static ArrayList<Short> primes = new ArrayList<>();
    static short[] ppCount = new short[MAX_NUM + 1];
	public static void main(String[] args) throws IOException {
	    primes.add((short)2);
    	for(short i = 3; i <= MAX_NUM; i += 2) {
    		if(!isComposite[i]) {
    		    primes.add(i);
    		    if(i <= 100) {
    	            for(int j = i * i; j <= MAX_NUM; j += i << 1)
    	                isComposite[j] = true;
    	        }
    		}
    	}
    	for(short i = 1; i <= 40; ++i)
    		ppCount[i - 1] = i;
    	ppCount[40] = ppCount[41] = 40;
    	for(int i = 42; i <= MAX_NUM; ++i) {
    	    ppCount[i] = ppCount[i - 1];
    		if(i % 41 == 0 || (i + 1) % 41 == 0)
    			continue;
    		if(producePrime(i))
    			++ppCount[i];
    	}
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
	    StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int a = (int)st.nval;
            st.nextToken();
            int b = (int)st.nval;
    	    output.append(String.format("%.2f\n", 100.0 * (ppCount[b] - ppCount[a] + (a == 0 || ppCount[a] > ppCount[a - 1] ? 1 : 0)) / (b - a + 1) + 0.000001));
        }
	    System.out.print(output);
	}
	
	static boolean producePrime(int n) {
        int num = n * n + n + 41;
        for(int i = 13; primes.get(i) < n; ++i) {
            if(num % primes.get(i) == 0)
                return false;
        }
    	return true;
    }
}
