import java.io.*;

public class Main {
	public static void main (String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		int n;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0)
		    output.append(n == 1 ? 1 : 2 * (n - (int)Math.pow(2, (int)(Math.log(n - 1) / Math.log(2)))) + "\n");
		System.out.print(output);
	}
}
