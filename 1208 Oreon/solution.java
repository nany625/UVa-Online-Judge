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
                    if(e1.weight != e2.weight)
                        return Integer.compare(e1.weight, e2.weight);
                    if(e1.parent == e2.parent)
                        return Integer.compare(e1.child, e2.child);
                    return Integer.compare(e1.parent, e2.parent);
                }
            });
            int count = 0;
            for(int j = 0; count < cities - 1; ++j) {
                int root1 = findRoot(root, edges.get(j).parent), root2 = findRoot(root, edges.get(j).child);
                if(root1 != root2) {
                    output.append((char)(edges.get(j).parent + 'A')).append('-').append((char)(edges.get(j).child + 'A')).append(' ').append(edges.get(j).weight).append('\n');
                    root[root2] = root1;
                    ++count;
                }
            }
		}
		System.out.print(output);
	}
	
	static int findRoot(int[] root, int child) {
        return root[child] == child ? child : (root[child] = findRoot(root, root[child]));
    }
}

class Edge {
    int parent, child, weight;
    Edge(int parent, int child, int weight) {
        this.parent = parent;
        this.child = child;
        this.weight = weight;
    }
}
