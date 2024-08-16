import java.io.*;

public class Main {
    static long[] dp = new long[30001];
    static int[] coins = {5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000};
	public static void main(String[] args) throws IOException {
		dp[0] = 1;
		for(int coin : coins) {
		    for(int i = coin; i <= 30000; ++i)
		        dp[i] += dp[i - coin];
		}
		StreamTokenizer st = new StreamTokenizer(System.in);
		double amount;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (amount = st.nval) != 0)
            output.append(String.format("%6.2f%17d\n", amount, dp[(int)(100 * amount + 0.1)]));
        System.out.print(output);
	}
}
