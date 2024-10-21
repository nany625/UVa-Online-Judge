import java.io.*;
import java.util.*;

public class Main {
    static long[] factorials = {
        1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 
        3628800, 39916800, 479001600, 6227020800L, 87178291200L, 1307674368000L, 20922789888000L, 355687428096000L, 6402373705728000L, 121645100408832000L
    };
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int samples = (int)st.nval;
        StringBuilder output = new StringBuilder();
    	while(samples-- > 0) {
    	    char[] S = br.readLine().toCharArray();
    	    long N = Long.parseLong(br.readLine());
    	    Arrays.sort(S);
    	    int len = S.length;
    	    for(int i = len - 1; i >= 0; --i) {
    	        int index = (int)(N / factorials[i]);
    	        output.append(S[index]);
    	        System.arraycopy(S, index + 1, S, index, len-- - index - 1);
		        N %= factorials[i];
		    }
		    output.append('\n');
		}
        System.out.print(output);
	}
}
