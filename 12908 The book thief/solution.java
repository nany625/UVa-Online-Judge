import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int s;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (s = (int)st.nval) != 0) {
		    int pages = ((-1 + (int)Math.sqrt(1 + (s << 3))) >> 1) + 1;
            output.append(((pages + 1) * pages >> 1) - s).append(' ').append(pages).append('\n');
		}
		System.out.print(output);
	}
}
