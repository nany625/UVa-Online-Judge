import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
        int n;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
            int exchange = (n - 3) / 2 + 1;
            output.append(exchange + (n - 2 * exchange) % 3 / 2 + "\n");
        }   
        System.out.print(output);
	}
}
