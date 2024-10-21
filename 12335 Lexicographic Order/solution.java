import java.io.*;

public class Main {
    static long[] factorials = {
        1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 
        3628800, 39916800, 479001600, 6227020800L, 87178291200L, 1307674368000L, 20922789888000L, 355687428096000L, 6402373705728000L, 121645100408832000L
    };
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
    	for(int i = 1; i <= T; ++i) {
    	    output.append("Case ").append(i).append(": ");
    	    st.nextToken();
    	    char[] s = st.sval.toCharArray();
    	    long k = Long.parseLong(br.readLine()) - 1;
    	    int len = s.length;
    	    char[] origin = new char[len];
    	    boolean[] used = new boolean[len];
    	    for(int j = len - 1; j >= 0; --j) {
                int index = (int)(k / factorials[j]), count = 0;
                for(int l = 0; l < len; ++l) {
                    if(!used[l]) {
                        if(count == index) {
                            origin[l] = s[len - 1 - j];
                            used[l] = true;
                            break;
                        } else
                            ++count;
                    }
                }
                k %= factorials[j];
            }
            for(int j = 0; j < len; ++j)
                output.append(origin[j]);
		    output.append('\n');
		}
        System.out.print(output);
	}
}
