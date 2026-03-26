import java.io.*;
import java.util.*;

public class Main {
    static int MAXV = 1000000;
    static int[] root = new int[MAXV + 1], rank = new int[MAXV + 1];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        boolean firstCase = true;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int N = (int)st.nval;
            if(!firstCase)
                output.append('\n');
            init(N);
		    int cost = 0;
		    for(int i = 1; i < N; ++i) {
		        st.nextToken();
		        st.nextToken();
		        st.nextToken();
		        cost += (int)st.nval;
    		}
    		output.append(cost).append('\n');
    		st.nextToken();
    		int K = (int)st.nval;
            ArrayList<Edge> edges = new ArrayList<>();
            while(K-- > 0) {
                st.nextToken();
                int u = (int)st.nval;
                st.nextToken();
                int v = (int)st.nval;
                st.nextToken();
                edges.add(new Edge(u, v, (int)st.nval));
            }
            st.nextToken();
    		int M = (int)st.nval;
    		while(M-- > 0) {
                st.nextToken();
                int u = (int)st.nval;
                st.nextToken();
                int v = (int)st.nval;
                st.nextToken();
                edges.add(new Edge(u, v, (int)st.nval));
            }
            edges.sort(new Comparator<Edge>() {
                @Override
                public int compare(Edge e1, Edge e2) {
                    return Integer.compare(e1.w, e2.w);
                }
            });
            int count = 0;
		    cost = 0;
		    for(int i = 0; count < N - 1; ++i) {
    		    int root1 = find(edges.get(i).u), root2 = find(edges.get(i).v);
    		    if(root1 != root2) {
    		        cost += edges.get(i).w;
    		        unite(root1, root2);
    		        ++count;
    		    }
    		}
    		output.append(cost).append('\n');
    		firstCase = false;
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
    Edge(int u, int v, int w) {
        this.u = u;
        this.v = v;
        this.w = w;
    }
}
