import java.io.*;

public class Main {
    static short[] factorCount = new short[1000001];
    static int[] table = new int[500000];
	public static void main(String[] args) throws IOException {
        for(int i = 3; i <= 1000000; ++i) {
            for(int j = i; j <= 1000000; j += i)
                ++factorCount[j];
        }
        short max = 2;
        table[0] = 2;
        for(int i = 4; i <= 1000000; i += 2) {
            if(max <= factorCount[i] + 2) {
                max = (short)(factorCount[i] + 2);
                table[(i >> 1) - 1] = i;
            } else
                table[(i >> 1) - 1] = table[(i >> 1) - 2];
        }
        StreamTokenizer st = new StreamTokenizer(System.in);
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
