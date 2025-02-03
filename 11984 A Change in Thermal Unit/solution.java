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
		    int C = (int)st.nval;
		    st.nextToken();
		    int d = (int)st.nval;
            output.append(String.format("Case %d: %.2f\n", i, (C * 1.8 + d) * 5 / 9));
        }
		System.out.print(output);
	}
}
