import java.io.*;
import java.util.*;

public class Main {
	static int INF = 50;
    static int[][] dist = new int[50][50];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int dataSets = 0, P;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (P = (int)st.nval) != 0) {
			for(int i = 0; i < P; ++i) {
				for(int j = 0; j < P; ++j)
					dist[i][j] = i == j ? 0 : INF;
			}
			st.nextToken();
		    int R = (int)st.nval;
		    HashMap<String, Integer> peopleID = new HashMap<>();
		    int id = 0;
		    while(R-- > 0) {
		    	st.nextToken();
		    	String name1 = st.sval;
		    	st.nextToken();
		    	String name2 = st.sval;
		    	if(!peopleID.containsKey(name1))
		    		peopleID.put(name1, id++);
		    	if(!peopleID.containsKey(name2))
		    		peopleID.put(name2, id++);
		    	dist[peopleID.get(name1)][peopleID.get(name2)] = dist[peopleID.get(name2)][peopleID.get(name1)] = 1;
		    }
		    floydWarshall(P);
		    int max = 0;
		    boolean disconnected = false;
		    for(int i = 0; i < P && !disconnected; ++i) {
		    	for(int j = 0; j < P && !disconnected; ++j)
		    		if(dist[i][j] == INF)
		    			disconnected = true;
		    		else
		    			max = Math.max(max, dist[i][j]);
		    }
		    output.append("Network ").append(++dataSets).append(": ").append(disconnected ? "DISCONNECTED" : max).append("\n\n");
		}
		System.out.print(output);
	}
	
	static void floydWarshall(int V) {
		for(int k = 0; k < V; ++k) {
			for(int i = 0; i < V; ++i) {
				for(int j = 0; j < V; ++j)
					dist[i][j] = Math.min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}
