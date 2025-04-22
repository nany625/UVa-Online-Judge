import java.io.*;
import java.util.*;

public class Main {
    static int MAXV = 1000;
    static int[] root = new int[MAXV];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        int n;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
            st.nextToken();
            int m = (int)st.nval;
            for(int i = 0; i < n; ++i)
    	        root[i] = i;
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
                    return Integer.compare(e1.w, e2.w);
                }
            });
            boolean isForest = true;
    		for(int i = 0; i < m; ++i) {
    			int root1 = find(edges[i].u), root2 = find(edges[i].v);
    			if(root1 != root2)
    				root[root2] = root1;
    			else {
    				if(!isForest)
    					output.append(' ');
    				output.append(edges[i].w);
    				isForest = false;
    			}
    		}
            if(isForest)
    			output.append("forest\n");
    		else
    			output.append('\n');
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
