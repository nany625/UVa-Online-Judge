import java.io.*;

public class Main {
    static int MAX_NUM = 100000, refusals;
    static int[] root = new int[MAX_NUM + 1], rank = new int[MAX_NUM + 1];
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
    		    unite(x, y);
    		}
		}
		System.out.print(output);
	}
    
    static void init() {
        for(int i = 0; i <= MAX_NUM; ++i)
            rank[root[i] = i] = 0;
        refusals = 0;
    }

    static int find(int x) {
    	return root[x] == x ? x : (root[x] = find(root[x]));
    }
    
    static void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x != y) {
            if(rank[x] > rank[y])
                root[y] = x;
            else if(rank[x] < rank[y])
                root[x] = y;
            else
                ++rank[root[y] = x];
        } else
            ++refusals;
    }
}
