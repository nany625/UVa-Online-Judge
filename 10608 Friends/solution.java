import java.io.*;

public class Main {
    static int MAXN = 30000;
    static int[] root = new int[MAXN + 1], depth = new int[MAXN + 1];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int cases = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(cases-- > 0) {
		    st.nextToken();
    		int N = (int)st.nval;
    		st.nextToken();
    		int M = (int)st.nval;
    		for(int n = 1; n <= N; ++n)
                depth[root[n] = n] = 1;
    		int max = 1;
    		while(M-- > 0) {
    		    st.nextToken();
        		int A = (int)st.nval;
        		st.nextToken();
        		int B = (int)st.nval;
        		int rootA = find(A), rootB = find(B);
        		if(rootA != rootB) {
        		    depth[rootA] += depth[rootB];
        		    max = Math.max(max, depth[rootA]);
        		    root[rootB] = rootA;
        		}
    		}
    		output.append(max).append('\n');
		}
		System.out.print(output);
	}
    
    static int find(int x) {
    	return root[x] == x ? x : (root[x] = find(root[x]));
    }
}
