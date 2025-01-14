import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    Graph graph = new Graph(); 
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int cases = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(cases-- > 0) {
			st.nextToken();
			graph.numVertices = (short)st.nval;
			graph.conn = (ArrayList<Short>[])new ArrayList[graph.numVertices + 1];
			for(int i = 1; i <= graph.numVertices; ++i)
			    graph.conn[i] = new ArrayList<>();
			int query = 0, succ = 0;
			String s;
			while((s = br.readLine()) != null && !s.isEmpty()) {
			    String[] tokens = s.split("\\s+");
			    short computeri = Short.parseShort(tokens[1]);
			    short computerj = Short.parseShort(tokens[2]);
			    if(tokens[0].charAt(0) == 'c') {
			        graph.conn[computeri].add(computerj);
			        graph.conn[computerj].add(computeri);
			    } else if(tokens[0].charAt(0) == 'q') {
			        ++query;
			        if(computeri == computerj)
			            ++succ;
			        else {
			            graph.visited = new boolean[graph.numVertices + 1];
			            boolean[] isConn = new boolean[1];
			            dfs(graph, computeri, computerj, isConn);
			            succ += isConn[0] ? 1 : 0;
			        }
			    }
			}
			output.append(succ).append(',').append(query - succ).append('\n');
			if(cases > 0)
			    output.append('\n');
		}
		System.out.print(output);
	}
	
	static void dfs(Graph graph, short computeri, short computerj, boolean[] isConn) {
        graph.visited[computeri] = true;
        for(int i = 0; i < graph.conn[computeri].size(); ++i) {
            if(graph.conn[computeri].get(i) == computerj) {
                isConn[0] = true;
                return;
            }
            if(!graph.visited[graph.conn[computeri].get(i)])
                dfs(graph, graph.conn[computeri].get(i), computerj, isConn);
        }
    }
}

class Graph {
    short numVertices;
    ArrayList<Short>[] conn;
    boolean[] visited; 
}
