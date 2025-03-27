import java.io.*;
import java.util.*;

public class Main {
	static int MAXN = 50000;
	static int[] sent = new int[MAXN + 1];
	static boolean[] visited1 = new boolean[MAXN + 1], visited2 = new boolean[MAXN + 1];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int T = (int)st.nval;
		StringBuilder output = new StringBuilder();
		for(int i = 1; i <= T; ++i) {
			st.nextToken();
			int N = (int)st.nval;
			for(int j = 0; j < N; ++j) {
				st.nextToken();
				int u = (int)st.nval;
				st.nextToken();
				sent[u] = (int)st.nval;
			}
			Arrays.fill(visited1, false);
			int m = 0, max = 0;
			for(int j = 1; j <= N; ++j) {
				if(!visited1[j]) {
					Arrays.fill(visited2, false);
					int[] count = new int[1];
					dfs(j, count);
					if(max < count[0]) {
						m = j;
						max = count[0];
					}
				}
			}
			output.append("Case ").append(i).append(": ").append(m).append('\n');
		}
		System.out.print(output);
	}
	
	static void dfs(int start, int[] count) {
		visited1[start] = visited2[start] = true;
		++count[0];
		if(!visited2[sent[start]])
			dfs(sent[start], count);
	}
}
