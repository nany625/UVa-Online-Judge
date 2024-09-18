import java.io.*;

public class Main {
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int N;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0)
		    output.append("f91(").append(N).append(") = ").append(N >= 101 ? N - 10 : 91).append('\n');
		System.out.print(output);
	}
}
