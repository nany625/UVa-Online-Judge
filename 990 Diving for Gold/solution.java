import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        boolean firstCase = true;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            if(!firstCase)
                output.append('\n');
            int t = (int)st.nval;
            st.nextToken();
            int w = (int)st.nval;
            st.nextToken();
            int n = (int)st.nval;
            Treasure[] treasures = new Treasure[n];
            for(int i = 0; i < n; ++i) {
                treasures[i] = new Treasure();
                st.nextToken();
                treasures[i].d = (int)st.nval;
                st.nextToken();
                treasures[i].v = (int)st.nval;
            }
            int[] dp = new int[t + 1];
            boolean[][] selected = new boolean[n][t + 1];
            for(int i = 0; i < n; ++i) {
                int d = 3 * w * treasures[i].d;
                int v = treasures[i].v;
                for(int j = t; j >= d; --j) {
                    if(dp[j] < dp[j - d] + v) {
                        dp[j] = dp[j - d] + v;
                        selected[i][j] = true;
                    }
                }
            }
            output.append(dp[t]).append('\n');
            int currentT = t;
            ArrayList<Integer> treasureID = new ArrayList<>();
            for(int i = n - 1; i >= 0; --i) {
                if(selected[i][currentT]) {
                    treasureID.add(i);
                    currentT -= 3 * w * treasures[i].d;
                }
            }
            output.append(treasureID.size()).append('\n');
            for(int i = treasureID.size() - 1; i >= 0; --i)
                output.append(treasures[treasureID.get(i)].d).append(' ').append(treasures[treasureID.get(i)].v).append('\n');
            firstCase = false;
        }
	    System.out.print(output);
	}
}

class Treasure {
    int d, v;
}
