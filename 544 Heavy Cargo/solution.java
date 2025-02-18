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
                    return Integer.compare(e2.w, e1.w);
                }
            });
            st.nextToken();
            int city1 = cityID.get(st.sval);
    		st.nextToken();
    		int city2 = cityID.get(st.sval);
    		for(int i = 0; i < id; ++i)
                root[i] = i;
            int i = 0;
            while(true) {
                int root1 = find(edges.get(i).u), root2 = find(edges.get(i).v);
                if(root1 != root2)
                    root[root2] = root1;
                if(find(city1) == find(city2)) {
                    output.append("Scenario #").append(++cases).append('\n').append(edges.get(i).w).append(" tons\n\n");
                    break;
                }
                ++i;
            }
		}
		System.out.print(output);
	}
	
	static int find(int x) {
    	return root[x] == x ? x : (root[x] = find(root[x]));
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
