import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
        int cases = 0, n;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
            output.append("Case " + (++cases) + ":\n");
            int[] set = new int[n];
            for(int i = 0; i < n; ++i) {
                st.nextToken();
                set[i] = (int)st.nval;
            }
            Arrays.sort(set);
            st.nextToken();
            int m = (int)st.nval;
            while(m-- > 0) {
                st.nextToken();
                int query = (int)st.nval, ans = set[0] + set[1];
                for(int i = 0; i < n - 1 && set[i] <= query; ++i) {
                    for(int j = i + 1; j < n; ++j) {
                        int sum = set[i] + set[j];
                        ans = Math.abs(query - ans) < Math.abs(query - sum) ? ans : sum;
                        if(sum > query)
                            break;
                    }
                }
                output.append("Closest sum to ").append(query).append(" is ").append(ans).append(".\n");
            }
    	}
        System.out.print(output);
	}
}
