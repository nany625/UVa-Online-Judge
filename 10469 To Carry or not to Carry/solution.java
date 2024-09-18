import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    int num1 = (int)st.nval;
		    st.nextToken();
		    output.append((num1 ^ (int)st.nval)).append('\n');
		}
		System.out.print(output);
	}
}
