import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
        for(int i = 1; i <= T; ++i) {
            st.nextToken();
            int N = (int)st.nval;
            st.nextToken();
            int prev = (int)st.nval;
            --N;
            int highJumps = 0, lowJumps = 0;
            while(N-- > 0) {
                st.nextToken();
                int curr = (int)st.nval;
                if(curr > prev)
                    ++highJumps;
                else if(curr < prev)
                    ++lowJumps;
                prev = curr;;
            }
            output.append("Case " + i + ": " + highJumps + " " + lowJumps + "\n");
        }
        System.out.print(output);
	}
}
