import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		int s;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (s = (int)st.nval) != 0) {
		    int pages = (-1 + (int)Math.sqrt(1 + 8 * s)) / 2 + 1;
            output.append((pages + 1) * pages / 2 - s).append(' ').append(pages).append('\n');
		}
		System.out.print(output);
	}
}
