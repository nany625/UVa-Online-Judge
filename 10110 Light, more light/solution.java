import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
	    long n;
	    StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (long)st.nval) != 0)
            output.append(Math.sqrt(n) == (int)Math.sqrt(n) ? "yes\n" : "no\n");
	    System.out.print(output);
	}
}
