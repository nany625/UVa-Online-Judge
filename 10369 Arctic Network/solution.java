import java.io.*;
import java.util.*;

public class Main {
    static int MAXV = 500;
    static int[] root = new int[MAXV];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int N = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(N-- > 0) {
            st.nextToken();
            int S = (int)st.nval;
            st.nextToken();
            int P = (int)st.nval;
            Coordinate[] outposts = new Coordinate[P];
            for(int i = 0; i < P; ++i) {
                outposts[i] = new Coordinate();
                st.nextToken();
                outposts[i].x = (int)st.nval;
                st.nextToken();
                outposts[i].y = (int)st.nval;
                root[i] = i;
            }
            Edge[] edges = new Edge[P * (P - 1) >> 1];
            int count = 0;
    		for(int i = 0; i < P - 1; ++i) {
    			for(int j = i + 1; j < P; ++j)
    				edges[count++] = new Edge(i, j, dist(outposts[i], outposts[j]));
    		}
    		Arrays.sort(edges, new Comparator<Edge>() {
    		    @Override
    		    public int compare(Edge e1, Edge e2) {
    		        return Integer.compare(e1.w, e2.w);
    		    }
    		});
    		int[] MST = new int[P - 1];
    		count = 0;
    		for(int i = 0; count < P - 1; ++i) {
    			int root1 = find(edges[i].u), root2 = find(edges[i].v);
    			if(root1 != root2) {
    				root[root2] = root1;
    				MST[count++] = edges[i].w;
    			}
    		}
    		output.append(String.format("%.2f\n", Math.sqrt(MST[P - 1 - S])));
        }
        System.out.print(output);
    }
    
    static int dist(Coordinate c1, Coordinate c2) {
    	return (c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y);
    }
    
    static int find(int x) {
    	return root[x] == x ? x : (root[x] = find(root[x]));
    }
}

class Coordinate {
    int x, y;
}

class Edge {
    int u, v, w;
    Edge(int u, int v, int w) {
        this.u = u;
        this.v = v;
        this.w = w;
    }
}
