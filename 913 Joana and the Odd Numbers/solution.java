import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
    	    long N = (long)st.nval;
    	    output.append(3 * N * N + 6 * N - 15 >> 1).append('\n');
    	}
        System.out.print(output);
	}
}
