import java.io.*;
import java.util.*;

public class Main {
    static int[] root = new int[101], rank = new int[101];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        int cases = 0, C;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (C = (int)st.nval) != 0) {
            st.nextToken();
            int S = (int)st.nval;
            st.nextToken();
            int Q = (int)st.nval;
            if(cases > 0)
                output.append('\n');
            output.append("Case #").append(++cases).append('\n');
            Edge[] edges = new Edge[S];
            for(int i = 0; i < S; ++i) {
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
                    return Integer.compare(e1.w, e2.w);
                }
            });
            while(Q-- > 0) {
                st.nextToken();
    		    int c1 = (int)st.nval;
    		    st.nextToken();
    		    int c2 = (int)st.nval;
    		    init(C);
    			boolean noPath = false;
    			for(int i = 0; i < S && !noPath; ++i) {
        			int root1 = find(edges[i].u), root2 = find(edges[i].v);
        			if(root1 != root2)
        				unite(root1, root2);
        			if(find(c1) == find(c2)) {
        			    output.append(edges[i].w).append('\n');
        			    noPath = true;
        			}
        		}
        		if(!noPath)
        		    output.append("no path\n");
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
