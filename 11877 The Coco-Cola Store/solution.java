import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int n;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
            int exchange = (n - 3 >> 1) + 1;
            output.append(exchange + (((n - (exchange << 1)) % 3) >> 1)).append('\n');
        }   
        System.out.print(output);
	}
}
