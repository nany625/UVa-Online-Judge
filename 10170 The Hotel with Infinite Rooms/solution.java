import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int S = (int)st.nval;
            st.nextToken();
            output.append((int)Math.ceil((-1 + Math.sqrt(1 + 4 * (S * S - S + 2 * (long)st.nval))) / 2)).append('\n');
		}
        System.out.print(output);
	}
}
