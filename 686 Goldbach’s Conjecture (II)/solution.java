import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 32763;
    static boolean[] isComposite = new boolean[(MAX_NUM >> 1) + 1];
    static ArrayList<Short> primes = new ArrayList<>();
    static short[] pairs = new short[(MAX_NUM >> 1) + 1];
	public static void main(String[] args) throws IOException {
    	eulerSieve();
        pairs[0] = 1;
        for(int i = 0; i < primes.size(); ++i) {
            for(int j = i, sum; j < primes.size() && (sum = primes.get(i) + primes.get(j)) <= 32766; ++j)
                ++pairs[(sum >> 1) - 2];
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int n;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0)
    		output.append(pairs[(n >> 1) - 2]).append('\n');
	    System.out.print(output);
	}
	
	static void eulerSieve() {
        for(short n = 3; n <= MAX_NUM; n += 2) {
            if(!isComposite[n >> 1])
                primes.add(n);
    	    for(int i = 0, temp; (temp = primes.get(i) * n) <= MAX_NUM; ++i) {
    	        isComposite[temp >> 1] = true;
    	        if(n % primes.get(i) == 0)
    	            break;
    	    }
        }
    }
}
