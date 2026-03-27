import java.io.*;

public class Main {
    static int MAXN = 50000;
    static int[] root = new int[MAXN + 1], rank = new int[MAXN + 1];
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int cases = 0;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int n = (int)st.nval;
            if(n == 0)
                break;
            st.nextToken();
            int m = (int)st.nval;
            init(n);
            while(m-- > 0) {
                st.nextToken();
                int rootI = find((int)st.nval);
                st.nextToken();
                int rootJ = find((int)st.nval);
                if(rootI != rootJ) {
                    --n;
                    unite(rootI, rootJ);
                }
            }
            output.append("Case ").append(++cases).append(": ").append(n).append('\n');
    	}
        System.out.print(output);
	}
	
	static void init(int n) {
        for(int i = 1; i <= n; ++i)
            rank[root[i] = i] = 0;
    }
    
    static int find(int x) {
    	return root[x] == x ? x : (root[x] = find(root[x]));
    }
    
    static void unite(int rootX, int rootY) {
        if(rank[rootX] > rank[rootY])
            root[rootY] = rootX;
        else if(rank[rootX] < rank[rootY])
            root[rootX] = rootY;
        else
            ++rank[root[rootY] = rootX];
    }
}
