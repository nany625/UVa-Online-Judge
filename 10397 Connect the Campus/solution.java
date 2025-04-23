import java.io.*;
import java.util.*;

public class Main {
    static int MAXV = 750;
    static int[] root = new int[MAXV];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int N = (int)st.nval;
            Coordinate[] buildings = new Coordinate[N];
            for(int i = 0; i < N; ++i) {
                buildings[i] = new Coordinate();
                st.nextToken();
                buildings[i].x = (int)st.nval;
                st.nextToken();
                buildings[i].y = (int)st.nval;
                root[i] = i;
            }
            Edge[] edges = new Edge[N * (N - 1) >> 1];
            int count = 0;
    		for(int i = 0; i < N - 1; ++i) {
    			for(int j = i + 1; j < N; ++j)
    				edges[count++] = new Edge(i, j, dist(buildings[i], buildings[j]));
    		}
    		Arrays.sort(edges, new Comparator<Edge>() {
    		    @Override
    		    public int compare(Edge e1, Edge e2) {
    		        return Integer.compare(e1.w, e2.w);
    		    }
    		});
    		st.nextToken();
    		int M = (int)st.nval;
    		count = 0;
    		while(M-- > 0) {
    		    st.nextToken();
    			int root1 = find((int)st.nval - 1);
    			st.nextToken();
    			int root2 = find((int)st.nval - 1);
    			if(root1 != root2) {
    				root[root2] = root1;
    				++count;
    			}
    		}
    		double length = 0;
    		for(int i = 0; count < N - 1; ++i) {
    			int root1 = find(edges[i].u), root2 = find(edges[i].v);
    			if(root1 != root2) {
    				length += Math.sqrt(edges[i].w);
    				root[root2] = root1;
    				++count;
    			}
    		}
    		output.append(String.format("%.2f\n", length));
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
