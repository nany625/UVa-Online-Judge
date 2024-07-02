import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
	    try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            StreamTokenizer st = new StreamTokenizer(br);
            st.nextToken();
            int cases = (int)st.nval;
            br.readLine();
            boolean blankLine = false;
            while(cases-- > 0) {
    		    if(blankLine)
                    System.out.println();
                HashMap<String, Integer> tree = new HashMap<>();
                ArrayList<String> treeKeys = new ArrayList<>();
                String species;
    	        while((species = br.readLine()) != null && !species.equals("")) {
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
                    System.out.printf("%s %.4f\n", s, 100.0 * tree.get(s) / treeSize);
                blankLine = true;
    		}
        } catch(IOException e) {};
	}
}
