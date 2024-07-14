import java.io.*;

public class Main {
	public static void main (String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		st.nextToken();
		int T = (int)st.nval;
		StringBuilder output = new StringBuilder();
		for(int i = 1; i <= T; ++i) {
		    st.nextToken();
            int a = (int)st.nval;
            st.nextToken();
            int b = (int)st.nval;
            a += (a + 1) % 2;
    	 	b -= (b + 1) % 2;
            output.append("Case " + i + ": " + (-a * a + b * b + 2 * a + 2 * b) / 4 + "\n");
        }
		System.out.print(output);
	}
}
