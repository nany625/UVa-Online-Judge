import java.io.*;
import java.math.*;

public class Main {
    static BigInteger[][] ans = new BigInteger[101][101];
	public static void main(String[] args) throws IOException {
	    for(int i = 1; i <= 100; ++i)
            ans[i][1] = new BigInteger("" + i);
        for(int i = 2; i <= 100; ++i) {
            ans[i - 1][i] = BigInteger.ZERO;
            for(int j = i; j <= 100; ++j)
                ans[j][i] = ans[j - 1][i - 1].add(ans[j - 1][i]);
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int N;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0) {
            st.nextToken();
            int M = (int)st.nval;
            output.append(N).append(" things taken ").append(M).append(" at a time is ").append(ans[N][M]).append(" exactly.\n");
        }
        System.out.print(output);
	}
}
