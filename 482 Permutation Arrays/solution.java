import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) {
	    try(BufferedReader br = new BufferedReader(new InputStreamReader(System.in))) {
            StreamTokenizer st = new StreamTokenizer(br);
            st.nextToken();
            int cases = (int)st.nval;
            boolean blankLine = false;
            while(cases-- > 0) {
    		    if(blankLine)
    		        System.out.println();
    			br.readLine();
    			TreeMap<Integer, String> map = new TreeMap<>();
    			String[] p = br.readLine().split("\\s+");
    			String[] x = br.readLine().split("\\s+");
    			int len = p.length;
    			for(int i = 0; i < len; ++i)
    				map.put(Integer.parseInt(p[i]), x[i]);
    			for(String s : map.values())
    				System.out.println(s);
    			blankLine = true;
    		}
        } catch(IOException e) {};
	}
}
