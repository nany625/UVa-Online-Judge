import java.io.*;
import java.util.*;

public class Main {
    static int MAXV = 750;
    static int[] root = new int[MAXV + 1];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int cases = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(cases-- > 0) {
            st.nextToken();
            int N = (int)st.nval;
            Coordinate[] towns = new Coordinate[N];
            for(int i = 0; i < N; ++i) {
                towns[i] = new Coordinate();
                st.nextToken();
                towns[i].x = (int)st.nval;
                st.nextToken();
                towns[i].y = (int)st.nval;
                root[i + 1] = i + 1;
            }
            st.nextToken();
    		int M = (int)st.nval, count = 0;
    		while(M-- > 0) {
    		    st.nextToken();
    			int root1 = find((int)st.nval);
    			st.nextToken();
    			int root2 = find((int)st.nval);
    			if(root1 != root2) {
    				root[root2] = root1;
    				++count;
    			}
    		}
    		if(count == N - 1)
	            output.append("No new highways need\n");
	        else {
	            Edge[] edges = new Edge[N * (N - 1) >> 1];
                int size = 0;
        		for(int i = 0; i < N - 1; ++i) {
        			for(int j = i + 1; j < N; ++j)
        				edges[size++] = new Edge(i + 1, j + 1, dist(towns[i], towns[j]));
        		}
        		Arrays.sort(edges, new Comparator<Edge>() {
        		    @Override
        		    public int compare(Edge e1, Edge e2) {
        		        if(e1.w != e2.w)
        		            return Integer.compare(e1.w, e2.w);
        		        if(e1.u != e2.u)
        		            return Integer.compare(e1.u, e2.u);
        		        return Integer.compare(e1.v, e2.v);
        		    }
        		});
        		for(int i = 0; count < N - 1; ++i) {
        	        int root1 = find(edges[i].u), root2 = find(edges[i].v);
        	        if(root1 != root2) {
        	            output.append(edges[i].u).append(' ').append(edges[i].v).append('\n');
        	            root[root2] = root1;
        	            ++count;
        	        }
        	    }
	        }
    		if(cases > 0)
        	    output.append('\n');
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
