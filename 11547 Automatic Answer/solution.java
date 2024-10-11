import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int t = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(t-- > 0) {
		    st.nextToken();
		    int n = (int)st.nval;
		    output.append(Math.abs((n * 63 + 7492) * 5 - 498) / 10 % 10).append('\n');
		}
		System.out.print(output);
	}
}
