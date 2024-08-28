import java.io.*;

public class Main {
	static long[] ans = new long[1000001];
	public static void main(String[] args) throws IOException {
	    for(int i = 4; i <= 1000000; ++i) {
            long temp = (i >> 1) - 1;
            ans[i] = ans[i - 1] + (1 + temp) * temp - temp * ((i + 1) & 1);
        }
	    StreamTokenizer st = new StreamTokenizer(System.in);
        int n;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) >= 3)
    	    output.append(ans[n]).append('\n');
        System.out.print(output);
	}
}
