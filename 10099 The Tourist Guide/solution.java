import java.io.*;
import java.util.*;

public class Main {
    static int[] root = new int[101], rank = new int[101];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        int scenario = 0;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int N = (int)st.nval;
            st.nextToken();
            int R = (int)st.nval;
            init(N);
            Edge[] edges = new Edge[R];
            for(int i = 0; i < R; ++i) {
                edges[i] = new Edge();
                st.nextToken();
                edges[i].u = (int)st.nval;
                st.nextToken();
                edges[i].v = (int)st.nval;
                st.nextToken();
                edges[i].w = (int)st.nval;
            }
            Arrays.sort(edges, new Comparator<Edge>() {
                @Override
                public int compare(Edge e1, Edge e2) {
                    return Integer.compare(e2.w, e1.w);
                }
            });
            st.nextToken();
            int S = (int)st.nval;
            st.nextToken();
            int D = (int)st.nval;
            st.nextToken();
            int T = (int)st.nval;
            for(int i = 0; i < R; ++i) {
    			int root1 = find(edges[i].u), root2 = find(edges[i].v);
    			if(root1 != root2)
    				unite(root1, root2);
    			if(find(S) == find(D)) {
    				output.append("Scenario #").append(++scenario).append("\nMinimum Number of Trips = ").append((int)Math.ceil(T / (edges[i].w - 1.0))).append("\n\n");
    				break;
    			}
    		}
        }
        System.out.print(output);
    }
    
    static void init(int V) {
        for(int n = 1; n <= V; ++n)
            rank[root[n] = n] = 0;
    }
    
    static int find(int x) {
    	return root[x] == x ? x : (root[x] = find(root[x]));
    }

    static void unite(int rootX, int rootY) {
        if(rank[rootX] > rank[rootY])
            root[rootY] = rootX;
        else if(rank[rootX] < rank[rootY])
            root[rootX] = rootY;
        else
            ++rank[root[rootY] = rootX];
    }
}

class Edge {
    int u, v, w;
}
