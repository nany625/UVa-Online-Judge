import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
        int cases = 0, n, m;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0 && st.nextToken() == StreamTokenizer.TT_NUMBER && (m = (int)st.nval) != 0) {
            int[] root = new int[n + 1];
            while(m-- > 0) {
                st.nextToken();
                int rootI = findRoot(root, (int)st.nval);
                st.nextToken();
                int rootJ = findRoot(root, (int)st.nval);
                if(rootI != rootJ) {
                    --n;
                    root[rootI] = root[rootJ];
                }
            }
            output.append("Case ").append(++cases).append(": ").append(n).append('\n');
    	}
        System.out.print(output);
	}
	
	static int findRoot(int[] root, int child) {
	    if(root[child] == 0 || root[child] == child)
	        return root[child] = child;
	    return root[child] = findRoot(root, root[child]);
	}
}
