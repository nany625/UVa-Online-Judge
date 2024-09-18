import java.io.*;

public class Main {
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int n;
		boolean firstCase = true;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
		    if(!firstCase)
                output.append('\n');
            Player[] table = new Player[n];
            for(int i = 0; i < n; ++i)
                table[i] = new Player();
            st.nextToken();
            int k = (int)st.nval, games = k * n * (n - 1) / 2;
            while(games-- > 0) {
                st.nextToken();
                int p1 = (int)st.nval;
                st.nextToken();
                String m1 = st.sval;
                st.nextToken();
                int p2 = (int)st.nval;
                st.nextToken();
                String m2 = st.sval;
                if((m1.charAt(0) == 'r' && m2.charAt(0) == 's') || (m1.charAt(0) == 'p' && m2.charAt(0) == 'r') || (m1.charAt(0) == 's' && m2.charAt(0) == 'p')) {
                    ++table[p1 - 1].win;
                    ++table[p2 - 1].lose;
                } else if((m1.charAt(0) == 'r' && m2.charAt(0) == 'p') || (m1.charAt(0) == 'p' && m2.charAt(0) == 's') || (m1.charAt(0) == 's' && m2.charAt(0) == 'r')) {
                    ++table[p2 - 1].win;
                    ++table[p1 - 1].lose;
                }
            }
            for(Player p : table) {
                if(p.win + p.lose == 0)
                    output.append("-\n");
                else
                    output.append(String.format("%.3f\n", (float)p.win / (p.win + p.lose)));
            }
            firstCase = false;
		}
		System.out.print(output);
	}
}

class Player {
    int win, lose;
    Player() {
        win = lose = 0;
    }
}
