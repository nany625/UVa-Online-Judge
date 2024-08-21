// #解法一
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int cases = (int)st.nval;
        br.readLine();
        StringBuilder output = new StringBuilder();
        boolean firstCase = true;
        while(cases-- > 0) {
    		if(!firstCase)
                output.append('\n');
            HashMap<String, Integer> tree = new HashMap<>();
            ArrayList<String> treeKeys = new ArrayList<>();
            String species;
    	    while((species = br.readLine()) != null && !species.isEmpty()) {
                if(tree.containsKey(species))
                	tree.replace(species, tree.get(species) + 1);
                else {
                	tree.put(species, 1);
                	treeKeys.add(species);
                }
            }
            Collections.sort(treeKeys);
            int treeSize = 0;
            for(Integer i : tree.values())
                treeSize += i;
            for(String s : treeKeys)
                output.append(String.format("%s %.4f\n", s, 100.0 * tree.get(s) / treeSize));
            firstCase = false;
        }
    	System.out.print(output);
	}
}

// #解法二
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int cases = (int)st.nval;
        br.readLine();
        StringBuilder output = new StringBuilder();
        boolean firstCase = true;
        while(cases-- > 0) {
    		if(!firstCase)
                output.append('\n');
            TreeMap<String, Integer> tree = new TreeMap<>();
            String species;
    	    while((species = br.readLine()) != null && !species.isEmpty())
                tree.put(species, tree.getOrDefault(species, 0) + 1);
            int treeSize = 0;
            for(Integer i : tree.values())
                treeSize += i;
            for(String s : tree.keySet())
                output.append(String.format("%s %.4f\n", s, 100.0 * tree.get(s) / treeSize));
            firstCase = false;
        }
    	System.out.print(output);
	}
}
