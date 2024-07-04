import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
        StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
    	    long N = (long)st.nval;
    	    output.append((3 * N * N + 6 * N - 15) / 2 + "\n");
    	}
        System.out.print(output);
	}
}
