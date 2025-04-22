import java.io.*;

public class Main {
    static int INF = 20;
    static int[][] dist = new int[21][21];
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int testSets = 0;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int X = (int)st.nval;
            output.append("Test Set #").append(++testSets).append('\n');
            for(int i = 1; i <= 20; ++i) {
    	        for(int j = 1; j <= 20; ++j)
    	            dist[i][j] = i == j ? 0 : INF;
    	    }
    	    while(X-- > 0) {
    	        st.nextToken();
    	        int v = (int)st.nval;
    	        dist[1][v] = dist[v][1] = 1;
    	    }
    	    for(int u = 2; u < 20; ++u) {
    	        st.nextToken();
    	        X = (int)st.nval;
    	        while(X-- > 0) {
        	        st.nextToken();
    	            int v = (int)st.nval;
        	        dist[u][v] = dist[v][u] = 1;
        	    }
    	    }
    	    floydWarshall();
	        st.nextToken();
    	    int N = (int)st.nval;
    	    while(N-- > 0) {
    	        st.nextToken();
        	    int A = (int)st.nval;
        	    st.nextToken();
        	    int B = (int)st.nval;
    	        output.append(String.format("%2d to %2d: %d\n", A, B, dist[A][B]));
    	    }
    	    output.append('\n');
    	}
        System.out.print(output);
	}
	
	static void floydWarshall() {
        for(int k = 1; k <= 20; ++k) {
            for(int i = 1; i <= 20; ++i) {
                for(int j = 1; j <= 20; ++j)
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
}
