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
			int[] root = new int[computers + 1];
			for(int i = 1; i <= computers; ++i)
			    root[i] = i;
			int query = 0, succ = 0;
			String s;
			while((s = br.readLine()) != null && !s.isEmpty()) {
			    String[] tokens = s.split("\\s+");
			    int computeri = Integer.parseInt(tokens[1]);
			    int computerj = Integer.parseInt(tokens[2]);
			    int rootI = findRoot(root, computeri);
			    int rootJ = findRoot(root, computerj);
			    if(tokens[0].charAt(0) == 'c') {
			        root[rootI] = root[rootJ];
			    } else if(tokens[0].charAt(0) == 'q') {
			        ++query;
			        succ += root[rootI] == root[rootJ] ? 1 : 0;
			    }
			}
			output.append(succ).append(',').append(query - succ).append('\n');
			if(cases > 0)
			    output.append('\n');
		}
		System.out.print(output);
	}
	
	static int findRoot(int[] root, int child) {
	    return root[child] == child ? child : (root[child] = findRoot(root, root[child]));
	}
}
