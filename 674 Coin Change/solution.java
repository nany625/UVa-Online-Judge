import java.io.*;

public class Main {
    static int[] dp = new int[7490], coins = {1, 5, 10, 25, 50};
	public static void main(String[] args) throws IOException {
	    dp[0] = 1;
	    for(int coin : coins) {
	        for(int i = coin; i <= 7489; ++i)
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
