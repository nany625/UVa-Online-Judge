import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
        for(int i = 1; i <= T; ++i) {
            st.nextToken();
            int N = (int)st.nval;
            int[] heights = new int[N];
            for(int j = 0; j < N; ++j) {
                st.nextToken();
                heights[j] = (int)st.nval;
            }
            int highJumps = 0, lowJumps = 0;
            for(int j = 1; j < N; ++j) {
                if(heights[j] > heights[j - 1])
                    ++highJumps;
                else if(heights[j] < heights[j - 1])
                    ++lowJumps;
            }
            output.append("Case ").append(i).append(": ").append(highJumps).append(' ').append(lowJumps).append('\n');
        }
        System.out.print(output);
	}
}
