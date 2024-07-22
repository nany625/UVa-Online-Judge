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
            String wall = br.readLine();
            int highJumps = 0, lowJumps = 0, len = wall.length();
            for(int j = 2; j < len; j += 2) {
                if(wall.charAt(j) > wall.charAt(j - 2))
                    ++highJumps;
                else if(wall.charAt(j) < wall.charAt(j - 2))
                    ++lowJumps;
            }
            output.append("Case " + i + ": " + highJumps + " " + lowJumps + "\n");
        }
        System.out.print(output);
	}
}
