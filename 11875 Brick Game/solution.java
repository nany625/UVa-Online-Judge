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
            int[] ages = new int[N];
            for(int j = 0; j < N; ++j) {
                st.nextToken();
                ages[j] = (int)st.nval;
            }
            output.append("Case ").append(i).append(": ").append(ages[N >> 1]).append('\n');
        }
	    System.out.print(output);
	}
}
