import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int a;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (a = (int)st.nval) != -1) {
			st.nextToken();
			int b = (int)st.nval;
			if(a > b) {
				int temp = a;
				a = b;
				b = temp;
			}
			output.append(Math.min(b - a, a + 100 - b)).append('\n');
		}
		System.out.print(output);
	}
}
