import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 200000;
    static int[] root = new int[MAX_NUM], depth = new int[MAX_NUM];
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int cases = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(cases-- > 0) {
		    HashMap<String, Integer> friendNum = new HashMap<>();
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
    		    int root1 = findRoot(friendNum.get(name1)), root2 = findRoot(friendNum.get(name2));
    		    if(root1 != root2) {
    		        depth[root[root1]] += depth[root[root2]];
                    root[root2] = root[root1];
    		    }
    		    output.append(depth[root[root1]]).append('\n');
    		}
		}
		System.out.print(output);
	}
    
    static int findRoot(int child) {
        return root[child] == child ? child : (root[child] = findRoot(root[child]));
    }
}
