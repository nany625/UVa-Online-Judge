import java.io.*;
import java.util.*;

public class Main {
    static int MAXV = 1000;
    static int[] root = new int[MAXV];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
        for(int i = 1; i <= T; ++i) {
            st.nextToken();
            int n = (int)st.nval;
            st.nextToken();
            int r = (int)st.nval;
            Coordinate[] cities = new Coordinate[n];
            for(int j = 0; j < n; ++j) {
                cities[j] = new Coordinate();
                st.nextToken();
                cities[j].x = (int)st.nval;
                st.nextToken();
                cities[j].y = (int)st.nval;
                root[j] = j;
            }
            Edge[] edges = new Edge[n * (n - 1) >> 1];
            int size = 0;
        	for(int j = 0; j < n - 1; ++j) {
        		for(int k = j + 1; k < n; ++k)
        			edges[size++] = new Edge(j, k, dist(cities[j], cities[k]));
        	}
        	Arrays.sort(edges, new Comparator<Edge>() {
        		@Override
        	    public int compare(Edge e1, Edge e2) {
        	        return Integer.compare(e1.w, e2.w);
        	    }
        	});
        	r *= r;
            double roadLen = 0, railroadLen = 0;
    	    int count = 0, groups = n;
    	    for(int j = 0; count < n - 1; ++j) {
    	        int root1 = find(edges[j].u), root2 = find(edges[j].v);
    	        if(root1 != root2) {
    	            root[root2] = root1;
    	            ++count;
    	            if(edges[j].w <= r) {
    	                roadLen += Math.sqrt(edges[j].w);
    	                --groups;
    	            } else
    	                railroadLen += Math.sqrt(edges[j].w);
    	        }
    	    }
    	    output.append("Case #").append(i).append(": ").append(groups).append(' ').append((int)(roadLen + 0.5)).append(' ').append((int)(railroadLen + 0.5)).append('\n');
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
