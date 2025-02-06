import java.io.*;

public class Main {
    static int MAX_NUM = 30000;
    static int[] root = new int[MAX_NUM + 1], depth = new int[MAX_NUM + 1];
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
        		int rootA = findRoot(A), rootB = findRoot(B);
        		if(rootA != rootB) {
        		    depth[root[rootA]] += depth[root[rootB]];
        		    max = Math.max(max, depth[root[rootA]]);
        		    root[rootB] = root[rootA];
        		}
    		}
    		output.append(max).append('\n');
		}
		System.out.print(output);
	}
    
    static int findRoot(int child) {
        return root[child] == child ? child : findRoot(root[child]);
    }
}
