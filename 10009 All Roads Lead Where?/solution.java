import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int cases = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(cases-- > 0) {
			st.nextToken();
			int m = (int)st.nval;
			st.nextToken();
			int n = (int)st.nval;
			HashMap<String, Integer> cityID = new HashMap<>();
			ArrayList<String> cityName = new ArrayList<>();
			Edge[] edges = new Edge[m];
			for(int i = 0; i < m; ++i) {
				st.nextToken();
				String city1 = st.sval;
				st.nextToken();
				String city2 = st.sval;
				if(!cityID.containsKey(city1)) {
					cityID.put(city1, cityName.size());
					cityName.add(city1);
				}
				if(!cityID.containsKey(city2)) {
					cityID.put(city2, cityName.size());
					cityName.add(city2);
				}
				edges[i] = new Edge(cityID.get(city1), cityID.get(city2));
			}
			ArrayList<Integer>[] conn = (ArrayList<Integer>[])new ArrayList[cityName.size()];
			for(int i = 0; i < conn.length; ++i)
				conn[i] = new ArrayList<>();
			for(Edge e : edges) {
				conn[e.parent].add(e.child);
				conn[e.child].add(e.parent);
			}
			while(n-- > 0) {
				st.nextToken();
				int start = cityID.get(st.sval);
				st.nextToken();
				int end = cityID.get(st.sval);
				int[] prev = new int[cityName.size()];
				boolean[] visited = new boolean[cityName.size()];
				visited[prev[start] = start] = true;
				ArrayList<Integer> curr = new ArrayList<>();
				curr.add(start);
				while(!visited[end]) {
					ArrayList<Integer> next = new ArrayList<>();
					for(int i = 0; i < curr.size(); ++i) {
						for(int j = 0; j < conn[curr.get(i)].size(); ++j) {
							if(!visited[conn[curr.get(i)].get(j)]) {
								next.add(conn[curr.get(i)].get(j));
								visited[conn[curr.get(i)].get(j)] = true;
								prev[conn[curr.get(i)].get(j)] = curr.get(i);
							}
						}
					}
					curr = new ArrayList<>(next);
				}
				ArrayList<Integer> route = new ArrayList<>();
				while(end != start) {
					route.add(end);
					end = prev[end];
				}
				output.append(cityName.get(start).charAt(0));
				for(int i = route.size() - 1; i >= 0; --i)
					output.append(cityName.get(route.get(i)).charAt(0));
				output.append('\n');
			}
			if(cases > 0)
				output.append('\n');
		}
		System.out.print(output);
	}
}

class Edge {
	int parent, child;
	Edge(int parent, int child) {
		this.parent = parent;
		this.child = child;
	}
}
