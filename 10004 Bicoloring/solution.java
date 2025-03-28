import java.io.*;
import java.util.*;

public class Main {
    static int MAXN = 199;
    static ArrayList<Short>[] edges;
    static char[] color = new char[MAXN];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		short n;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (short)st.nval) != 0) {
		    edges = (ArrayList<Short>[])new ArrayList[n];
		    for(int i = 0; i < n; ++i)
		        edges[i] = new ArrayList<>();
		    st.nextToken();
		    short l = (short)st.nval, startVertex = 0;
		    while(l-- > 0) {
		        st.nextToken();
    		    short a = (short)st.nval;
    		    st.nextToken();
    		    short b = (short)st.nval;
    		    edges[a].add(b);
    		    edges[b].add(startVertex = a);
		    }
		    Arrays.fill(color, '\0');
		    boolean[] bicolorable = {true};
		    dfs(startVertex, '0', bicolorable);
		    output.append(bicolorable[0] ? "BICOLORABLE.\n" : "NOT BICOLORABLE.\n");
		}
        System.out.print(output);
	}
	
	static void dfs(short startVertex, char c, boolean[] bicolorable) {
        color[startVertex] = c;
        for(int i = 0; i < edges[startVertex].size(); ++i) {
            if(color[edges[startVertex].get(i)] == '\0')
                dfs(edges[startVertex].get(i), c == '0' ? '1' : '0', bicolorable);
            else if(color[edges[startVertex].get(i)] == c) {
                bicolorable[0] = false;
                return;
            }
        }
    }
}
