import java.io.*;
import java.util.*;

public class Main {
    static int[] root = new int[200];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int cases = 0;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    int n = (int)st.nval;
		    st.nextToken();
		    int r = (int)st.nval;
		    if(n == 0)
		        break;
    		HashMap<String, Integer> cityID = new HashMap<>();
    		ArrayList<Edge> edges = new ArrayList<>();
    		int id = 0;
    		while(r-- > 0) {
    		    st.nextToken();
    		    String city1 = st.sval;
    		    st.nextToken();
    		    String city2 = st.sval;
    		    st.nextToken();
    		    int w = (int)st.nval;
    		    if(!cityID.containsKey(city1))
    		        cityID.put(city1, id++);
    		    if(!cityID.containsKey(city2))
    		        cityID.put(city2, id++);
    		    edges.add(new Edge(cityID.get(city1), cityID.get(city2), w));
    		}
            edges.sort(new Comparator<Edge>() {
                @Override
                public int compare(Edge e1, Edge e2) {
                    return Integer.compare(e2.weight, e1.weight);
                }
            });
            st.nextToken();
    		String city1 = st.sval;
    		st.nextToken();
    		String city2 = st.sval;
    		for(int i = 0; i < id; ++i)
                root[i] = i;
            int limit = 10000;
            for(int i = 0; findRoot(cityID.get(city1)) != findRoot(cityID.get(city2)); ++i) {
                int root1 = findRoot(edges.get(i).parent), root2 = findRoot(edges.get(i).child);
                if(root1 != root2) {
                    root[root2] = root1;
                    limit = Math.min(limit, edges.get(i).weight);
                }
            }
            output.append("Scenario #").append(++cases).append('\n').append(limit).append(" tons\n\n");
		}
		System.out.print(output);
	}
	
	static int findRoot(int child) {
        return root[child] == child ? child : (root[child] = findRoot(root[child]));
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
