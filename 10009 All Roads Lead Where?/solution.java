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
			int[] cityID = new int[26];
			Arrays.fill(cityID, -1);
			Edge[] edges = new Edge[m];
			ArrayList<String> cityName = new ArrayList<>();
			for(int i = 0; i < m; ++i) {
				st.nextToken();
				String city1 = st.sval;
				st.nextToken();
				String city2 = st.sval;
				if(cityID[city1.charAt(0) - 'A'] == -1) {
				    cityID[city1.charAt(0) - 'A'] = cityName.size();
				    cityName.add(city1);
				}
				if(cityID[city2.charAt(0) - 'A'] == -1) {
				    cityID[city2.charAt(0) - 'A'] = cityName.size();
				    cityName.add(city2);
				}
				edges[i] = new Edge(cityID[city1.charAt(0) - 'A'], cityID[city2.charAt(0) - 'A']);
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
				int start = cityID[st.sval.charAt(0) - 'A'];
				st.nextToken();
				int end = cityID[st.sval.charAt(0) - 'A'];
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
