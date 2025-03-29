import java.io.*;

public class Main {
    static int MAXN = 1000000;
	static long[] ans = new long[MAXN + 1];
	public static void main(String[] args) throws IOException {
	    for(int n = 4; n <= MAXN; ++n) {
            long temp = (n >> 1) - 1;
            ans[n] = ans[n - 1] + (1 + temp) * temp - temp * ((n + 1) & 1);
        }
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int n;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) >= 3)
    	    output.append(ans[n]).append('\n');
        System.out.print(output);
	}
}
