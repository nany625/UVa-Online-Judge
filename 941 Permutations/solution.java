import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
	    try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
	        long[] factorials = {
                1L, 2L, 6L, 24L, 120L, 720L, 5040L, 40320L, 362880L, 3628800L, 
                39916800L, 479001600L, 6227020800L, 87178291200L, 1307674368000L, 20922789888000L, 355687428096000L, 6402373705728000L, 121645100408832000L
            };
            StreamTokenizer st = new StreamTokenizer(br);
            st.nextToken();
            int samples = (int)st.nval;
    		while(samples-- > 0) {
    		    st.nextToken();
    		    char[] S = st.sval.toCharArray();
    		    long N = Long.parseLong(br.readLine());
    		    Arrays.sort(S);
    		    int len = S.length;
    		    for(int i = len - 2; i >= 0; --i) {
    		        int index = (int)(N / factorials[i]);
    		        System.out.print(S[index]);
    		        System.arraycopy(S, index + 1, S, index, len-- - index - 1);
    		        N %= factorials[i];
    		    }
    		    System.out.println(S[0]);
    		}
        } catch(IOException e) {};
	}
}
