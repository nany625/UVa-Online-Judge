import java.io.*;

public class Main {
    static int MAX_AMOUNT = 9999;
    static long[] dp = new long[MAX_AMOUNT + 1];
    static int[] coins = {
        1, 8, 27, 64, 125, 216, 343, 512, 729, 1000, 
        1331, 1728, 2197, 2744, 3375, 4096, 4913, 5832, 6859, 8000, 
        9261
    };
	public static void main(String[] args) throws IOException {
		dp[0] = 1;
		for(Integer coin : coins) {
		    for(int i = coin; i <= MAX_AMOUNT; ++i)
		        dp[i] += dp[i - coin];
		}
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER)
		    output.append(dp[(int)st.nval]).append('\n');
		System.out.print(output);
	}
}
