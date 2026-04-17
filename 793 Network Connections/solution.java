import java.io.*;
import java.util.*;

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
			String line;
			while((line = br.readLine()) != null && !line.isEmpty()) {
                StringTokenizer strtok = new StringTokenizer(line);
                char command = strtok.nextToken().charAt(0);
			    int computeri = Integer.parseInt(strtok.nextToken());
			    int computerj = Integer.parseInt(strtok.nextToken());
			    if(command == 'c')
			        unite(root, rank, computeri, computerj);
			    else if(command == 'q') {
			        if(find(root, computeri) == find(root, computerj))
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
	
	static void unite(int[] root, int[] rank, int x, int y) {
        x = find(root, x);
        y = find(root, y);
        if(x != y) {
            if(rank[x] > rank[y])
                root[y] = x;
            else if(rank[x] < rank[y])
                root[x] = y;
            else
                ++rank[root[y] = x];
        }
    }
}
