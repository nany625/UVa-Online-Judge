import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    int n = (int)st.nval;
		    st.nextToken();
		    int k = (int)st.nval;
            output.append(n + (int)Math.floor((n - k) / (k - 1.0)) + 1).append('\n');
		}
		System.out.print(output);
	}
}
