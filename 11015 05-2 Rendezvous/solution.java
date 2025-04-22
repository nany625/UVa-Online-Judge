import java.io.*;

public class Main {
    static int INF = 1000000000;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        int cases = 0, N;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0) {
            st.nextToken();
            int M = (int)st.nval;
            int[][] dist = new int[N][N];
            String[] names = new String[N];
            for(int i = 0; i < N; ++i) {
                st.nextToken();
                names[i] = st.sval;
                for(int j = 0; j < N; ++j)
                    dist[i][j] = i == j ? 0 : INF;
            }
            while(M-- > 0) {
                st.nextToken();
                int i = (int)st.nval;
                st.nextToken();
                int j = (int)st.nval;
                st.nextToken();
                int k = (int)st.nval;
                dist[i - 1][j - 1] = dist[j - 1][i - 1] = k;
            }
            floydWarshall(dist, N);
            int minCost = INF, minIndex = -1;
            for(int i = 0; i < N; ++i) {
                int cost = 0;
                for(int j = 0; j < N; ++j)
                    cost += dist[i][j];
                if(minCost > cost) {
                    minCost = cost;
                    minIndex = i;
                }
            }
            output.append("Case #").append(++cases).append(" : ").append(names[minIndex]).append('\n');
        }
        System.out.print(output);
    }
    
    static void floydWarshall(int[][] dist, int V) {
        for(int k = 0; k < V; ++k) {
            for(int i = 0; i < V; ++i) {
                for(int j = 0; j < V; ++j)
                    dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
}
}
