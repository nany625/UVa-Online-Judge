import java.io.*;
import java.util.*;

public class Main {
    static short MAX_NUM = 10000;
    static boolean[] isComposite = new boolean[(MAX_NUM >> 1) + 1];
    static ArrayList<Short> primes = new ArrayList<>();
	static short[] count = new short[MAX_NUM + 1];
	public static void main(String[] args) throws IOException {
    	eulerSieve();
	    for(int i = 0; i < primes.size(); ++i) {
            for(int j = i, sum = 0; j < primes.size() && (sum += primes.get(j)) <= MAX_NUM; ++j)
                ++count[sum];
        }
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
    	int num;
    	StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER && (num = (int)st.nval) != 0)
	        output.append(count[num]).append('\n');
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
}
