import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            String X = br.readLine();
            st.nextToken();
            String Y = br.readLine();
            output.append(levenshteinDistance(X, Y)).append('\n');
        }
	    System.out.print(output);
	}
	
	static int min(int a, int b, int c) {
	    return Math.min(Math.min(a, b), c);
	}
	
	static int levenshteinDistance(String X, String Y) {
	    int[] dp = new int[Y.length() + 1];
	    for(int i = 0; i < dp.length; ++i)
	        dp[i] = i;
	    for(int i = 1; i <= X.length(); ++i) {
	        int prev = dp[0];
	        dp[0] = i;
	        for(int j = 1; j < dp.length; ++j) {
	            int temp = dp[j];
	            if(X.charAt(i - 1) == Y.charAt(j - 1))
	                dp[j] = prev;
	            else
	                dp[j] = 1 + min(dp[j], dp[j - 1], prev);
	            prev = temp;
	        }
	    }
	    return dp[dp.length - 1];
	}
}
