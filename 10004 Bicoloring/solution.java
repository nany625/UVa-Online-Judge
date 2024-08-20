import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		Graph graph = new Graph();
		StreamTokenizer st = new StreamTokenizer(System.in);
		BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(System.out));
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (graph.numVertices = (short)st.nval) != 0) {
		    graph.edges = (ArrayList<Short>[])new ArrayList[graph.numVertices];
		    for(int i = 0; i < graph.numVertices; ++i)
		        graph.edges[i] = new ArrayList<>();
		    st.nextToken();
		    short l = (short)st.nval, startVertex = 0;
		    while(l-- > 0) {
		        st.nextToken();
    		    short a = (short)st.nval;
    		    st.nextToken();
    		    short b = (short)st.nval;
    		    graph.edges[a].add(b);
    		    graph.edges[b].add(startVertex = a);
		    }
		    graph.color = new char[graph.numVertices];
		    graph.visited = new boolean[graph.numVertices];
		    boolean[] bicolorable = {true};
		    dfs(graph, startVertex, '0', bicolorable);
		    output.append(bicolorable[0] ? "BICOLORABLE.\n" : "NOT BICOLORABLE.\n");
		}
        writer.write(output.toString());
        writer.flush();
        writer.close();
	}
	
	static void dfs(Graph graph, short startVertex, char color, boolean[] bicolorable) {
        graph.visited[startVertex] = true;
        graph.color[startVertex] = color;
        int size = graph.edges[startVertex].size();
        for(int i = 0; i < size; ++i) {
            if(!graph.visited[graph.edges[startVertex].get(i)])
                dfs(graph, graph.edges[startVertex].get(i), color == '0' ? '1' : '0', bicolorable);
            else if(graph.color[graph.edges[startVertex].get(i)] == color) {
                bicolorable[0] = false;
                return;
            }
        }
    }
}

class Graph {
    short numVertices;
    ArrayList<Short>[] edges;
    char[] color;
    boolean[] visited;
}
