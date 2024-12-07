import java.io.*;
import java.util.*;

public class Main {
    static short MAX_NUM = 1000;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
    static ArrayList<Short> primes = new ArrayList<>();
    static short[] pos = new short[MAX_NUM + 1];
    static StringBuilder output = new StringBuilder();
	public static void main(String[] args) throws IOException {
        eulerSieve();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int N = (int)st.nval;
            st.nextToken();
            int C = (int)st.nval;
            output.append(N).append(' ').append(C).append(':');
            if((pos[N] & 1) == 0 && C << 1 < pos[N])
        		printPrimes((pos[N] >> 1) - C, (pos[N] >> 1) + C - 1);
        	else if((pos[N] & 1) == 1 && (C << 1) - 1 < pos[N])
        		printPrimes((pos[N] + 1 >> 1) - C, (pos[N] - 3 >> 1) + C);
        	else
        		printPrimes(0, pos[N] - 1);
    	    output.append("\n\n");
        }
        System.out.print(output);
	}
	
	static void eulerSieve() {
        primes.add(pos[1] = 1);
        for(short n = 2; n <= MAX_NUM; ++n) {
            pos[n] = pos[n - 1];
            if(!isComposite[n]) {
                primes.add(n);
                ++pos[n];
            }
            for(int i = 1, temp; i < primes.size() && (temp = primes.get(i) * n) <= MAX_NUM; ++i) {
                isComposite[temp] = true;
                if(n % primes.get(i) == 0)
                    break;
            }
        }
    }
    
    static void printPrimes(int first, int last) {
    	for(int i = first; i <= last; ++i)
    		output.append(' ').append(primes.get(i));
    }
}
