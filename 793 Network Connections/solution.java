import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int cases = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(cases-- > 0) {
			st.nextToken();
			int computers = (int)st.nval;
			int[] root = new int[computers + 1], rank = new int[computers + 1];
			init(root, rank, computers);
			int succ = 0, unsucc = 0;
			String s;
			while((s = br.readLine()) != null && !s.isEmpty()) {
			    String[] tokens = s.split("\\s+");
			    int computeri = Integer.parseInt(tokens[1]);
			    int computerj = Integer.parseInt(tokens[2]);
			    int rootI = find(root, computeri);
			    int rootJ = find(root, computerj);
			    if(tokens[0].charAt(0) == 'c')
			        unite(root, rank, rootI, rootJ);
			    else if(tokens[0].charAt(0) == 'q') {
			        if(root[rootI] == root[rootJ])
			            ++succ;
			        else
			            ++unsucc;
                }
			}
			output.append(succ).append(',').append(unsucc).append('\n');
			if(cases > 0)
			    output.append('\n');
		}
		System.out.print(output);
	}
	
	static void init(int[] root, int[] rank, int n) {
        for(int i = 1; i <= n; ++i)
    		rank[root[i] = i] = 0;
    }
    
	static int find(int[] root, int x) {
	    return root[x] == x ? x : (root[x] = find(root, root[x]));
	}
	
	static void unite(int[] root, int[] rank, int rootX, int rootY) {
        if(rootX != rootY) {
            if(rank[rootX] > rank[rootY])
                root[rootY] = rootX;
            else if(rank[rootX] < rank[rootY])
                root[rootX] = rootY;
            else
                ++rank[root[rootY] = rootX];
        }
    }
}
