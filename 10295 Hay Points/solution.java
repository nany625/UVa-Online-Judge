import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
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
	    StringBuilder output = new StringBuilder();
        while(n-- > 0) {
		    String description;
		    int salary = 0;
		    while(st.nextToken() == StreamTokenizer.TT_WORD && !(description = st.sval).equals(".")) {
		        if(dictionary.containsKey(description))
		            salary += dictionary.get(description);
		    }
		    output.append(salary).append('\n');
		}
	    System.out.print(output);
	}
}
