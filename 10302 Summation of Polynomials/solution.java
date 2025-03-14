import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            long x = (long)st.nval;
            output.append((x + 1) * (x + 1) * x * x >> 2).append('\n');
        }
        System.out.print(output);
	}
}
