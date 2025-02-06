import java.io.*;

public class Main {
    static int MAX_NUM = 50000;
    static int[] root = new int[MAX_NUM + 1];
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int cases = 0, n, m;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0 && st.nextToken() == StreamTokenizer.TT_NUMBER && (m = (int)st.nval) != 0) {
            for(int i = 1; i <= n; ++i)
                root[i] = i;
            while(m-- > 0) {
                st.nextToken();
                int rootI = findRoot((int)st.nval);
                st.nextToken();
                int rootJ = findRoot((int)st.nval);
                if(rootI != rootJ) {
                    --n;
                    root[rootJ] = root[rootI];
                }
            }
            output.append("Case ").append(++cases).append(": ").append(n).append('\n');
    	}
        System.out.print(output);
	}
	
	static int findRoot(int child) {
	    return root[child] == child ? child : (root[child] = findRoot(root[child]));
	}
}
