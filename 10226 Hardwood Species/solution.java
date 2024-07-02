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
                ArrayList<Species> tree = new ArrayList<>();
                String species;
    	        while((species = br.readLine()) != null && !species.equals("")) {
                    int pos = binarySearch(tree, species);
                    if(pos < tree.size() && tree.get(pos).name.equals(species))
                        ++tree.get(pos).count;
                    else
                        tree.add(pos, new Species(species, (short)1));
                }
                int treeSize = 0;
                for(Species s : tree)
                    treeSize += s.count;
                for(Species s : tree)
                    System.out.printf("%s %.4f\n", s.name, 100.0 * s.count / treeSize);
                blankLine = true;
    		}
        } catch(IOException e) {};
	}
	
	static int binarySearch(ArrayList<Species> tree, String key) {
        int left = 0, right = tree.size() - 1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            int cmp = tree.get(mid).name.compareTo(key);
            if(cmp == 0)
                return mid;
            if(cmp < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
}

class Species {
    String name;
    short count;
    Species(String name, short count) {
        this.name = name;
        this.count = count;
    }
}
