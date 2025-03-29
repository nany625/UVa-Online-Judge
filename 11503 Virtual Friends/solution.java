import java.io.*;
import java.util.*;

public class Main {
    static int MAXF = 200000;
    static int[] root = new int[MAXF], depth = new int[MAXF];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int cases = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(cases-- > 0) {
		    Map<String, Integer> friendNum = new HashMap<>();
		    st.nextToken();
    		int F = (int)st.nval, count = 0;
    		while(F-- > 0) {
    		    st.nextToken();
    		    String name1 = st.sval;
    		    st.nextToken();
    		    String name2 = st.sval;
    		    if(!friendNum.containsKey(name1)) {
    		        friendNum.put(name1, count);
    		        root[count] = count;
    		        depth[count++] = 1;
    		    }
    		    if(!friendNum.containsKey(name2)) {
    		        friendNum.put(name2, count);
    		        root[count] = count;
    		        depth[count++] = 1;
    		    }
    		    int root1 = find(friendNum.get(name1)), root2 = find(friendNum.get(name2));
    		    if(root1 != root2) {
    		        depth[root1] += depth[root2];
                    root[root2] = root1;
    		    }
    		    output.append(depth[root1]).append('\n');
    		}
		}
		System.out.print(output);
	}
    
    static int find(int x) {
    	return root[x] == x ? x : (root[x] = find(root[x]));
    }
}
