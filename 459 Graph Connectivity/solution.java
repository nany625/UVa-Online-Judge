import java.io.*;

public class Main {
    static int[] root = new int[26], rank = new int[26];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
    	int cases = (int)st.nval;
    	br.readLine();
		StringBuilder output = new StringBuilder();
		while(cases-- > 0) {
    		int[] subgraphs = new int[1];
    		subgraphs[0] = br.readLine().charAt(0) - 'A' + 1;
    		init(subgraphs[0]);
            String s;
            while((s = br.readLine()) != null && !s.isEmpty())
                unite(s.charAt(0) - 'A', s.charAt(1) - 'A', subgraphs);
            output.append(subgraphs[0]).append('\n');
            if(cases > 0)
                output.append('\n');
		}
		System.out.print(output);
	}
	
	static void init(int n) {
        for(int i = 0; i < n; ++i)
            rank[root[i] = i] = 0;
    }

    static int find(int x) {
    	return root[x] == x ? x : (root[x] = find(root[x]));
    }

    static void unite(int x, int y, int[] subgraphs) {
        x = find(x);
        y = find(y);
        if(x != y) {
            --subgraphs[0];
            if(rank[x] > rank[y])
                root[y] = x;
            else if(rank[x] < rank[y])
                root[x] = y;
            else
                ++rank[root[y] = x];
        }
    }
}
