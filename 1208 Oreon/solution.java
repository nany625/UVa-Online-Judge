import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int cases = (int)st.nval;
		StringBuilder output = new StringBuilder();
		for(int i = 1; i <= cases; ++i) {
    		output.append("Case ").append(i).append(":\n");
    		st.nextToken();
    		int cities = (int)st.nval;
    		int[] root = new int[cities];
    		ArrayList<Edge> edges = new ArrayList<>();
    		for(int j = 0; j < cities; ++j) {
                root[j] = j;
                for(int k = 0; k < cities; ++k) {
                    st.nextToken();
                    int w = (int)st.nval;
                    if(w > 0 && j < k)
                        edges.add(new Edge(j, k, w));
                    if(k < cities - 1)
                        st.nextToken();
                }
            }
            edges.sort(new Comparator<Edge>() {
                @Override
                public int compare(Edge e1, Edge e2) {
                    if(e1.w != e2.w)
                        return Integer.compare(e1.w, e2.w);
                    if(e1.u != e2.u)
                        return Integer.compare(e1.u, e2.u);
                    return Integer.compare(e1.v, e2.v);
                }
            });
            int count = 0;
            for(int j = 0; count < cities - 1; ++j) {
                int root1 = find(root, edges.get(j).u), root2 = find(root, edges.get(j).v);
                if(root1 != root2) {
                    output.append((char)(edges.get(j).u + 'A')).append('-').append((char)(edges.get(j).v + 'A')).append(' ').append(edges.get(j).w).append('\n');
                    root[root2] = root1;
                    ++count;
                }
            }
		}
		System.out.print(output);
	}
	
	static int find(int[] root, int x) {
    	return root[x] == x ? x : (root[x] = find(root, root[x]));
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
