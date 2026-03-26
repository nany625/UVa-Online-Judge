import java.io.*;
import java.util.*;

public class Main {
    static int MAXV = 9999;
    static int[] root = new int[MAXV + 1], rank = new int[MAXV + 1];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int c = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(c-- > 0) {
            st.nextToken();
            int n = (int)st.nval;
            st.nextToken();
            int m = (int)st.nval;
            Edge[] edges = new Edge[m];
            for(int i = 0; i < m; ++i) {
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
            init(n);
            int cost = 0;
            for(int i = 0; i < m; ++i) {
    	        int root1 = find(edges[i].u), root2 = find(edges[i].v);
    	        if(root1 != root2)
    	            unite(root1, root2);
    	        else
    	            cost += edges[i].w;
    	    }
            output.append(cost).append('\n');
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
