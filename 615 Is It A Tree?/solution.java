// #解法一
import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 50000;
    static int[] root = new int[MAX_NUM + 1];
    static ArrayList<Integer> nodes;
    static boolean isTree;
	public static void main(String[] args) throws IOException {
	    init();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int cases = 0;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
    		int parent = (int)st.nval;
    		st.nextToken();
    		int child = (int)st.nval;
    		if(parent < 0)
    		    break;
    		if(parent == 0 && child == 0) {
                if(!isTree)
                    output.append("Case ").append(++cases).append(" is not a tree.\n");
                else {
                    int rootCount = 0;
                    for(int i = 0; i < nodes.size() && rootCount <= 1; ++i) {
                        if(nodes.get(i) == find(nodes.get(i)))
                            ++rootCount;
                    }
                    output.append("Case ").append(++cases).append(rootCount <= 1 ? " is a tree.\n" : " is not a tree.\n");
                }
                init();
            } else {
                int rootParent = find(parent), rootChild = find(child);
                if(rootParent != rootChild)
                    root[rootChild] = rootParent;
                else
                    isTree = false;
            }
		}
		System.out.print(output);
	}

    static void init() {
        Arrays.fill(root, 0);
        nodes = new ArrayList<>();
        isTree = true;
    }
    
    static int find(int x) {
        if(root[x] == 0) {
            nodes.add(x);
            return root[x] = x;
        }
    	return root[x] == x ? x : (root[x] = find(root[x]));
    }
}

// #解法二
import java.io.*;
import java.util.*;

public class Main {
    static HashMap<Integer, ArrayList<Integer>> conn;
    static HashMap<Integer, Integer> parentCount;
    static int edgeCount, startVertex;
    static boolean isTree;
	public static void main(String[] args) throws IOException {
		init();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int cases = 0, parent, child;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (parent = (int)st.nval) >= 0 && st.nextToken() == StreamTokenizer.TT_NUMBER && (child = (int)st.nval) >= 0) {
            if(parent == 0 && child == 0) {
                if(!isTree)
                    output.append("Case ").append(++cases).append(" is not a tree.\n");
                else if(edgeCount == 0)
                    output.append("Case ").append(++cases).append(" is a tree.\n");
                else {
                    HashMap<Integer, Boolean> visited = new HashMap<>();
                    int[] nodeCount = new int[1];
                    dfs(visited, startVertex, nodeCount);
                    if(nodeCount[0] == edgeCount + 1)
                        output.append("Case ").append(++cases).append(" is a tree.\n");
                    else
                        output.append("Case ").append(++cases).append(" is not a tree.\n");
                }
                init();
            } else {
                if(conn.containsKey(parent))
                    conn.get(parent).add(child);
                else {
                    conn.put(parent, new ArrayList<>());
                    conn.get(parent).add(child);
                }
                if(conn.containsKey(child))
                    conn.get(child).add(parent);
                else {
                    conn.put(child, new ArrayList<>());
                    conn.get(child).add(parent);
                }
                if(parentCount.containsKey(child))
                    isTree = false;
                else
                    parentCount.put(child, 1);
                ++edgeCount;
                startVertex = parent;
            }
        }
        System.out.print(output);
	}
	
	static void init() {
	    conn = new HashMap<>();
		parentCount = new HashMap<>();
		edgeCount = startVertex = 0;
		isTree = true;
	}
	
	static void dfs(HashMap<Integer, Boolean> visited, int vertex, int[] nodeCount) {
        if(!visited.containsKey(vertex)) {
            visited.put(vertex, true);
            ++nodeCount[0];
            for(Integer nextVertex : conn.get(vertex))
                dfs(visited, nextVertex, nodeCount);
        }
    }
}
