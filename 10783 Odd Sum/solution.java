import java.io.*;

public class Main {
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int T = (int)st.nval;
		StringBuilder output = new StringBuilder();
		for(int i = 1; i <= T; ++i) {
		    st.nextToken();
            int a = (int)st.nval;
            st.nextToken();
            int b = (int)st.nval;
            a += (a + 1) & 1;
    	 	b -= (b + 1) & 1;
            output.append("Case ").append(i).append(": ").append(- a * a + b * b + (a << 1) + (b << 1) >> 2).append('\n');
        }
		System.out.print(output);
	}
}
