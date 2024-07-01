import java.io.*;
import java.util.*;

public class Main {
    static char[][] table = new char[250][250];
	public static void main(String[] args) {
	    try {
	        StreamTokenizer st = new StreamTokenizer(System.in);
	        st.nextToken();
	        int m = (int)st.nval;
	        st.nextToken();
	        int n = (int)st.nval;
	        HashMap<String, Integer> dictionary = new HashMap<>();
	        while(m-- > 0) {
	            st.nextToken();
	            String word = st.sval;
	            st.nextToken();
		        dictionary.put(word, (int)st.nval);
            }
            while(n-- > 0) {
    		    String description;
    		    int salary = 0;
    		    while(st.nextToken() == StreamTokenizer.TT_WORD && !(description = st.sval).equals(".")) {
    		        for(String s : dictionary.keySet()) {
    		            if(description.equals(s)) {
    		                salary += dictionary.get(s);
    		                break;
    		            }
    		        }
    		    }
    		    System.out.println(salary);
    		}
	    } catch(IOException e) {}
	}
}
