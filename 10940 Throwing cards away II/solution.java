import java.io.*;

public class Main {
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int n;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0)
		    output.append(n == 1 ? 1 : n - (1 << (int)(Math.log(n - 1) / Math.log(2))) << 1).append('\n');
		System.out.print(output);
	}
}
