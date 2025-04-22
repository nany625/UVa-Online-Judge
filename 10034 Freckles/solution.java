import java.io.*;
import java.util.*;

public class Main {
    static int MAXV = 100;
    static int[] root = new int[MAXV];
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int cases = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(cases-- > 0) {
            st.nextToken();
            int n = (int)st.nval;
            Coordinate[] freckles = new Coordinate[n];
            for(int i = 0; i < n; ++i) {
                freckles[i] = new Coordinate();
                st.nextToken();
                freckles[i].x = st.nval;
                st.nextToken();
                freckles[i].y = st.nval;
                root[i] = i;
            }
            Edge[] edges = new Edge[n * (n - 1) >> 1];
            int size = 0;
            for(int i = 0; i < n - 1; ++i) {
                for(int j = i + 1; j < n; ++j)
                    edges[size++] = new Edge(i, j, dist(freckles[i], freckles[j]));
            }
            Arrays.sort(edges, new Comparator<Edge>() {
                @Override
                public int compare(Edge e1, Edge e2) {
                    return Double.compare(e1.w, e2.w);
                }
            });
            int count = 0;
            double length = 0;
            for(int i = 0; count < n - 1; ++i) {
                int root1 = find(edges[i].u), root2 = find(edges[i].v);
                if(root1 != root2) {
                    length += Math.sqrt(edges[i].w);
                    root[root2] = root1;
                    ++count;
                }
            }
            output.append(String.format("%.2f\n", length));
            if(cases > 0)
                output.append('\n');
        }
        System.out.print(output);
    }
    
    static double dist(Coordinate c1, Coordinate c2) {
        return (c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y);
    }
    
    static int find(int x) {
    	return root[x] == x ? x : (root[x] = find(root[x]));
    }
}

class Coordinate {
    double x, y;
}

class Edge {
    int u, v;
    double w;
    Edge(int u, int v, double w) {
        this.u = u;
        this.v = v;
        this.w = w;
    }
}
