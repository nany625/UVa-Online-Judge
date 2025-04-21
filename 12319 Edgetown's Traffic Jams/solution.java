import java.io.*;

public class Main {
    static int INF = 100, MAXV = 100;
    static int[][] dist = new int[MAXV + 1][MAXV + 1], newDist = new int[MAXV + 1][MAXV + 1];
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StreamTokenizer st = new StreamTokenizer(br);
	public static void main(String[] args) throws IOException {
		int n;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
            for(int i = 1; i <= n; ++i) {
                for(int j = 1; j <= n; ++j)
                    dist[i][j] = newDist[i][j] = i == j ? 0 : INF;
            }
            input(dist, n);
            floydWarshall(dist, n);
            input(newDist, n);
            floydWarshall(newDist, n);
            st.nextToken();
            int A = (int)st.nval;
            st.nextToken();
            int B = (int)st.nval;
            output.append(accept(n, A, B) ? "Yes\n" : "No\n");
        }
	    System.out.print(output);
	}
	
	static void input(int[][] array, int V) throws IOException {
	    for(int u = 1; u <= V; ++u) {
	        st.nextToken();
	        String[] tokens = br.readLine().split("\\s+");
	        for(String s : tokens)
	            array[u][Integer.parseInt(s)] = 1;
	    }
	}
	
	static void floydWarshall(int[][] array, int V) {
        for(int k = 1; k <= V; ++k) {
            for(int i = 1; i <= V; ++i) {
                for(int j = 1; j <= V; ++j)
                    array[i][j] = Math.min(array[i][j], array[i][k] + array[k][j]);
            }
        }
    }
    
    static boolean accept(int V, int A, int B) {
        for(int i = 1; i <= V; ++i) {
            for(int j = 1; j <= V; ++j) {
                if(newDist[i][j] > A * dist[i][j] + B)
                    return false;
            }
        }
        return true;
    }
}
