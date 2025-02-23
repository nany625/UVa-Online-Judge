import java.io.*;

public class Main {
    static int[] root = new int[26];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
    	int cases = (int)st.nval;
    	br.readLine();
		StringBuilder output = new StringBuilder();
		while(cases-- > 0) {
    		int subgraphs = br.readLine().charAt(0) - 'A' + 1;
    		for(int n = 0; n < subgraphs; ++n)
                root[n] = n;
            String s;
            while((s = br.readLine()) != null && !s.isEmpty()) {
                int root1 = find(s.charAt(0) - 'A'), root2 = find(s.charAt(1) - 'A');
                if(root1 != root2) {
                    --subgraphs;
                    root[root2] = root1;
                }
            }
            output.append(subgraphs).append('\n');
            if(cases > 0)
                output.append('\n');
		}
		System.out.print(output);
	}

    static int find(int x) {
    	return root[x] == x ? x : (root[x] = find(root[x]));
    }
}
