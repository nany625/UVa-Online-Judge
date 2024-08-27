import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
    	StreamTokenizer st = new StreamTokenizer(System.in);
    	long N;
    	StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (long)st.nval) >= 0)
	        output.append(((1 + N) * N >> 1) + 1).append('\n');
	    System.out.print(output);
	}
}
