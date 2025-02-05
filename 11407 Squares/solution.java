import java.io.*;

public class Main {
    static int MAX_AMOUNT = 10000;
    static int[] dp = new int[MAX_AMOUNT + 1], coins = new int[100];
    public static void main(String[] args) throws IOException {
        for(int n = 1; n <= 100; ++n)
            coins[n - 1] = n * n;
        for(int i = 1; i <= MAX_AMOUNT; ++i) {
            dp[i] = MAX_AMOUNT;
            for(int j = 0; j < 100; ++j) {
                if(i >= coins[j])
                    dp[i] = Math.min(dp[i], dp[i - coins[j]] + 1);
            }
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int t = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(t-- > 0) {
            st.nextToken();
            output.append(dp[(int)st.nval]).append('\n');
        }
        System.out.print(output);
    }
}
