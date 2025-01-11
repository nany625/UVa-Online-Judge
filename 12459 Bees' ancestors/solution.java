import java.io.*;

public class Main {
	static long[] ans = new long[81];
	public static void main(String[] args) throws IOException {
		ans[1] = 1;
		ans[2] = 2;
		for(int n = 3; n < 81; ++n)
	        ans[n] = ans[n - 2] + ans[n - 1];
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int generation;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (generation = (int)st.nval) != 0)
			output.append(ans[generation]).append('\n');
		System.out.print(output);
	}
}
