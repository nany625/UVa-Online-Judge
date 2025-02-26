import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(T-- > 0) {
            String s = br.readLine();
            output.append(LCS(s)).append('\n');
        }
        System.out.print(output);
	}
	
	static int LCS(String X) {
        int[] dp = new int[X.length() + 1];
        for(int i = 0; i < X.length(); ++i) {
            int prev = 0;
            for(int j = 1; j <= X.length(); ++j) {
                int temp = dp[j];
                if(X.charAt(i) == X.charAt(X.length() - j))
                    dp[j] = prev + 1;
                else
                    dp[j] = dp[j] > dp[j - 1] ? dp[j] : dp[j - 1];
                prev = temp;
            }
        }
        return dp[X.length()];
    }
}
