import java.io.*;
import java.util.*;

public class Main {
    static int MAXV = 9999;
    static int[] root = new int[MAXV + 1];
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
            for(int i = 1; i <= n; ++i)
                root[i] = i;
            int cost = 0;
            for(int i = 0; i < m; ++i) {
    	        int root1 = find(edges[i].u), root2 = find(edges[i].v);
    	        if(root1 != root2)
    	            root[root2] = root1;
    	        else
    	            cost += edges[i].w;
    	    }
            output.append(cost).append('\n');
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
