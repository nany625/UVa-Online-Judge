import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
			int M = (int)st.nval;
			st.nextToken();
			int N = (int)st.nval;
			if(M + N == 0)
				break;
			output.append(solve(M, N)).append(" knights may be placed on a ").append(M).append(" row ").append(N).append(" column board.\n");
		}
		System.out.print(output);
	}
	
	static int specialCase(int n) {
		if((n & 1) == 1)
			return 1;
		return n;
	}
	
	static int solve(int M, int N) {
		if(M > N) {
			int temp = M;
			M = N;
			N = temp;
		}
		if(M == 0)
			return 0;
		if(M == 1)
			return N;
		if(M == 2)
			return N + specialCase(N & 3);
		return M * N + 1 >> 1;
	}
}
