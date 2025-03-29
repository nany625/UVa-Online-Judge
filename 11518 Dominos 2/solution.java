import java.io.*;
import java.util.*;

public class Main {
    static int MAXN = 10000;
    static ArrayList<Short>[] knock;
    static boolean[] visited;
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int cases = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(cases-- > 0) {
            st.nextToken();
            short n = (short)st.nval;
            st.nextToken();
            short m = (short)st.nval;
            st.nextToken();
            short l = (short)st.nval;
            knock = (ArrayList<Short>[])new ArrayList[n + 1];
            for(int i = 1; i <= n; ++i)
                knock[i] = new ArrayList<>();
            while(m-- > 0) {
                st.nextToken();
                short x = (short)st.nval;
                st.nextToken();
                short y = (short)st.nval;
                knock[x].add(y);
            }
            visited = new boolean[n + 1];
            int[] count = new int[1];
            while(l-- > 0) {
                st.nextToken();
                short z = (short)st.nval;
                if(!visited[z])
                    dfs(z, count);
            }
            output.append(count[0]).append('\n');
    	}
        System.out.print(output);
	}
	
	static void dfs(short start, int[] count) {
	    visited[start] = true;
	    ++count[0];
	    for(Short s : knock[start]) {
	        if(!visited[s])
	            dfs(s, count);
	    }
	}
}
