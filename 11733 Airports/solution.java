import java.io.*;
import java.util.*;

public class Main {
    static int MAXV = 10000;
    static int[] root = new int[MAXV + 1];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
        for(int i = 1; i <= T; ++i) {
            st.nextToken();
            int N = (int)st.nval;
            st.nextToken();
            int M = (int)st.nval;
            st.nextToken();
            int A = (int)st.nval;
            Edge[] edges = new Edge[M];
            for(int j = 0; j < M; ++j) {
                edges[j] = new Edge();
                st.nextToken();
                edges[j].u = (int)st.nval;
                st.nextToken();
                edges[j].v = (int)st.nval;
                st.nextToken();
                edges[j].w = (int)st.nval;
            }
            Arrays.sort(edges, new Comparator<Edge>() {
                @Override
                public int compare(Edge e1, Edge e2) {
                    return Integer.compare(e1.w, e2.w);
                }
            });
            for(int j = 1; j <= N; ++j)
                root[j] = j;
            int cost = 0, airports = N, count = 0;
            for(int j = 0; j < M && count < N - 1; ++j) {
                int root1 = find(edges[j].u), root2 = find(edges[j].v);
                if(root1 != root2) {
                    if(A > edges[j].w) {
                        cost += edges[j].w;
                        --airports;
                    }
                    root[root2] = root1;
                    ++count;
                }
            }
            output.append("Case #").append(i).append(": ").append(cost + airports * A).append(' ').append(airports).append('\n');
        }
        System.out.print(output);
    }
    
    static int find(int x) {
    	return root[x] == x ? x : (root[x] = find(root[x]));
    }
}

class Edge {
    int u, v, w;
}
