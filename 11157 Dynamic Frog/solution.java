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
    		st.nextToken();
    		int D = (int)st.nval;
    		Stone[] stones = new Stone[N + 2];
    		stones[0] = new Stone();
    		stones[0].M = 0;
    		for(int j = 1; j <= N; ++j) {
    		    stones[j] = new Stone();
                stones[j].S = (char)br.read();
                br.read();
                st.nextToken();
                stones[j].M = (int)st.nval;
            }
            stones[N + 1] = new Stone();
    		stones[N + 1].M = D;
    		int max = 0;
    		for(int j = 1; j <= N; ++j) {
                switch(stones[j].S) {
                    case 'B':
                        max = Math.max(max, stones[j].M - stones[j - 1].M);
                        break;
                    case 'S':
                        max = Math.max(max, stones[j + 1].M - stones[j - 1].M);
                }
            }
            max = Math.max(max, D - stones[N].M);
            output.append("Case ").append(i).append(": ").append(max).append('\n');
		}
		System.out.print(output);
	}
}

class Stone {
    char S;
    int M;
}
