import java.io.*;

public class Main {
	public static void main (String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		int N;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0)
		    output.append("f91(" + N + ") = " + (N >= 101 ? N - 10 : 91) + "\n");
		System.out.print(output);
	}
}
