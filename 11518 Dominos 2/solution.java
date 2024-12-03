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
            st.nextToken();
            short m = (short)st.nval;
            st.nextToken();
            short l = (short)st.nval;
            graph.knockList = (ArrayList<Short>[])new ArrayList[graph.numVertices + 1];
            for(int i = 1; i <= graph.numVertices; ++i)
                graph.knockList[i] = new ArrayList<>();
            while(m-- > 0) {
                st.nextToken();
                short x = (short)st.nval;
                st.nextToken();
                short y = (short)st.nval;
                graph.knockList[x].add(y);
            }
            graph.visited = new boolean[graph.numVertices + 1];
            int[] count = new int[1];
            while(l-- > 0) {
                st.nextToken();
                short z = (short)st.nval;
                if(!graph.visited[z])
                    dfs(graph, z, count);
            }
            output.append(count[0]).append('\n');
    	}
        System.out.print(output);
	}
	
	static void dfs(Graph graph, short startVertex, int[] count) {
	    graph.visited[startVertex] = true;
	    ++count[0];
	    for(int i = 0; i < graph.knockList[startVertex].size(); ++i) {
	        if(!graph.visited[graph.knockList[startVertex].get(i)])
	            dfs(graph, graph.knockList[startVertex].get(i), count);
	    }
	}
}

class Graph {
    short numVertices;
    ArrayList<Short>[] knockList;
    boolean[] visited;
}
