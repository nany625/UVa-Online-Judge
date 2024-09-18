import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int n = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(n-- > 0) {
    	    st.nextToken();
            int m = (int)st.nval, sum = 0;
            int[] coins = new int[m];
            for(int i = 0; i < m; ++i) {
                st.nextToken();
                sum += coins[i] = (int)st.nval;
            }
    	    int temp = sum >> 1, max = 0;
    	    boolean[] subsetSum = new boolean[temp + 1];
    	    subsetSum[0] = true;
    	    for(int i = 0; i < m && max < temp; ++i) {
    	        for(int j = temp; j >= coins[i] && max < temp; --j) {
                    if(subsetSum[j] |= subsetSum[j - coins[i]])
                        max = Math.max(max, j);
                }
    	    }
    	    output.append(sum - (max << 1)).append('\n');
    	}
        System.out.print(output);
	}
}
