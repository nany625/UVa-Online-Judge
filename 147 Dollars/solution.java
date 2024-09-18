import java.io.*;

public class Main {
    static long[] dp = new long[6001];
    static int[] coins = {1, 2, 4, 10, 20, 40, 100, 200, 400, 1000, 2000};
	public static void main(String[] args) throws IOException {
		dp[0] = 1;
		for(int coin : coins) {
		    for(int i = coin; i <= 6000; ++i)
		        dp[i] += dp[i - coin];
		}
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		double amount;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (amount = st.nval) != 0)
            output.append(String.format("%6.2f%17d\n", amount, dp[(int)(20 * amount)]));
        System.out.print(output);
	}
}
