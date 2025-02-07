import java.io.*;

public class Main {
    static int MAX_NUM = 100000, refusals;
    static int[] root = new int[MAX_NUM + 1];
	public static void main(String[] args) throws IOException {
	    init();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
    		int x = (int)st.nval;
    		if(x == -1) {
    		    output.append(refusals).append('\n');
    		    init();
    		} else {
    		    st.nextToken();
    		    int y = (int)st.nval;
    		    int rootX = findRoot(x), rootY = findRoot(y);
    		    if(rootX == rootY)
    		        ++refusals;
    		    else
    		        root[rootY] = rootX;
    		}
		}
		System.out.print(output);
	}
    
    static void init() {
        for(int n = 0; n <= MAX_NUM; ++n)
            root[n] = n;
        refusals = 0;
    }

    static int findRoot(int child) {
        return root[child] == child ? child : (root[child] = findRoot(root[child]));
    }
}
