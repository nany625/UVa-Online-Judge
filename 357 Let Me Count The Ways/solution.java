import java.io.*;

public class Main {
    static int MAX_AMOUNT = 30000;
    static long[] dp = new long[MAX_AMOUNT + 1];
    static int[] coins = {1, 5, 10, 25, 50};
	public static void main(String[] args) throws IOException {
		dp[0] = 1;
		for(int coin : coins) {
            for(int i = coin; i <= MAX_AMOUNT; ++i)
                dp[i] += dp[i - coin];
        }
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int n = (int)st.nval;
            if(dp[n] == 1)
                output.append("There is only 1 way to produce ").append(n).append(" cents change.\n");
            else
	            output.append("There are ").append(dp[n]).append(" ways to produce ").append(n).append(" cents change.\n");
        }
        System.out.print(output);
	}
}
