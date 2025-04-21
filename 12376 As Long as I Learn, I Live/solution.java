import java.io.*;

public class Main {
    static int MAXV = 100;
    static int[][] conn = new int[MAXV][MAXV], dist = new int[MAXV][MAXV];
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
        for(int i = 1; i <= T; ++i) {
            int[] connCount = new int[MAXV];
            st.nextToken();
            int n = (int)st.nval;
            st.nextToken();
            int m = (int)st.nval;
            int[] units = new int[n];
            for(int j = 0; j < n; ++j) {
                st.nextToken();
                units[j] = (int)st.nval;
            }
            while(m-- > 0) {
                st.nextToken();
                int u = (int)st.nval;
                st.nextToken();
                int v = (int)st.nval;
                conn[u][connCount[u]++] = v;
                dist[u][v] = units[v];
            }
            int start = 0, gain = 0;
            while(connCount[start] > 0) {
                int maxIndex = 0, maxDist = 0;
                for(int j = 0; j < connCount[start]; ++j) {
                    if(maxDist < dist[start][conn[start][j]])
                        maxDist = dist[start][maxIndex = conn[start][j]];
                }
                gain += maxDist;
                start = maxIndex;
            }
            output.append("Case ").append(i).append(": ").append(gain).append(' ').append(start).append('\n');
        }
	    System.out.print(output);
	}
}
