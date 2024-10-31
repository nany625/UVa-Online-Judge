import java.io.*;
import java.util.*;

public class Main {
    static short MAX_NUM = 1000;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
    static ArrayList<Short> primes = new ArrayList<>();
    static short[] pos = new short[MAX_NUM];
	public static void main(String[] args) throws IOException {
        primes.add(pos[0] = 1);
        primes.add(pos[1] = 2);
	    for(short i = 3; i <= MAX_NUM; ++i) {
	        pos[i - 1] = pos[i - 2];
	        if((i & 1) == 1 && !isComposite[i]) {
	            primes.add(i);
	            ++pos[i - 1];
	            if(i <= 31) {
    	            for(int j = i * i; j <= MAX_NUM; j += i)
    	                isComposite[j] = true;
    	        }
	        }
	    }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int N = (int)st.nval;
            st.nextToken();
            int C = (int)st.nval;
            output.append(N).append(' ').append(C).append(':');
            if((pos[N - 1] & 1) == 0 && C << 1 < pos[N - 1])
        		output.append(printPrimes((pos[N - 1] >> 1) - C, (pos[N - 1] >> 1) + C - 1));
        	else if((pos[N - 1] & 1) == 1 && (C << 1) - 1 < pos[N - 1])
        		output.append(printPrimes((pos[N - 1] + 1 >> 1) - C, (pos[N - 1] - 3 >> 1) + C));
        	else
        		output.append(printPrimes(0, pos[N - 1] - 1));
    	    output.append("\n\n");
        }
        System.out.print(output);
	}
    
    static StringBuilder printPrimes(int first, int last) {
        StringBuilder ans = new StringBuilder();
    	for(int i = first; i <= last; ++i)
    		ans.append(' ').append(primes.get(i));
    	return ans;
    }
}
