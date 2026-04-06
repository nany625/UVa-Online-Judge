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
    		int subgraphs = br.readLine().charAt(0) - 'A' + 1;
    		init(subgraphs);
            String s;
            while((s = br.readLine()) != null && !s.isEmpty()) {
                int root1 = find(s.charAt(0) - 'A'), root2 = find(s.charAt(1) - 'A');
                if(root1 != root2) {
                    unite(root1, root2);
                    --subgraphs;
                }
            }
            output.append(subgraphs).append('\n');
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

    static void unite(int rootX, int rootY) {
        if(rank[rootX] > rank[rootY])
            root[rootY] = rootX;
        else if(rank[rootX] < rank[rootY])
            root[rootX] = rootY;
        else
            ++rank[root[rootY] = rootX];
    }
}
