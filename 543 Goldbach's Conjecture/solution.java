import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 999995;
    static boolean[] isComposite = new boolean[(MAX_NUM >> 1) + 1];
    static ArrayList<Integer> primes = new ArrayList<>();
	public static void main(String[] args) throws IOException {
    	eulerSieve();
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
    	int n;
    	StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
	        int i = 0;
	        while(isComposite[n - primes.get(i) >> 1])
	            ++i;
	        output.append(n).append(" = ").append(primes.get(i)).append(" + ").append(n - primes.get(i)).append('\n');
    	}
	    System.out.print(output);
	}
	
	static void eulerSieve() {
        for(int n = 3; n <= MAX_NUM; n += 2) {
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
