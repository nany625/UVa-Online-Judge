import java.io.*;

public class Main {
    static int MAXN = 1000000, MOD = 1000000007;
    static long[] ans = new long[MAXN + 1];
	public static void main(String[] args) throws IOException {
	    ans[1] = ans[2] = 1;
	    for(int n = 3; n <= MAXN; ++n) {
    		if((n & 1) == 1)
    			ans[n] = ans[n - 1] * n % MOD;
    		else
    			ans[n] = ans[n - 2] * (n >> 1) % MOD * (n >> 1) % MOD;
    	}
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER)
		    output.append(ans[(int)st.nval]).append('\n');
		System.out.print(output);
	}
}
