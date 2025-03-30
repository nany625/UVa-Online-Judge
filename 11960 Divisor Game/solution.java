import java.io.*;

public class Main {
    static int MAXN = 1000000;
    static short[] factorCount = new short[MAXN + 1];
    static int[] table = new int[MAXN >> 1];
	public static void main(String[] args) throws IOException {
        for(int i = 3; i <= MAXN; ++i) {
            for(int j = i; j <= MAXN; j += i)
                ++factorCount[j];
        }
        short max = 2;
        table[0] = 2;
        for(int i = 4; i <= MAXN; i += 2) {
            if(max <= factorCount[i] + 2) {
                max = (short)(factorCount[i] + 2);
                table[(i >> 1) - 1] = i;
            } else
                table[(i >> 1) - 1] = table[(i >> 1) - 2];
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(T-- > 0) {
            st.nextToken();
    		int N = (int)st.nval;
    		if(N == 1 || N == 3)
    	        output.append(N).append('\n');
    	    else
    	        output.append(table[(N >> 1) - 1]).append('\n');
		}
	    System.out.print(output);
	}
}
