import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
	    int cases = (int)st.nval;
	    br.readLine();
	    boolean firstCase = true;
        StringBuilder output = new StringBuilder();
    	while(cases-- > 0) {
    	    if(!firstCase)
    	        output.append('\n');
    	    String plaintext = br.readLine(), substitution = br.readLine();
    	    output.append(substitution + "\n" + plaintext + "\n");
    	    int len = plaintext.length();
    	    HashMap<Character, Character> cypher = new HashMap<>();
    	    for(int i = 0; i < len; ++i)
    	        cypher.put(plaintext.charAt(i), substitution.charAt(i));
    	    String text;
    	    while((text = br.readLine()) != null && !text.isEmpty()) {
    	        len = text.length();
    	        for(int i = 0; i < len; ++i)
    	            output.append(cypher.containsKey(text.charAt(i)) ? (char)cypher.get(text.charAt(i)) : text.charAt(i));
    	        output.append('\n');
    	    }
    	    firstCase = false;
    	}
        System.out.print(output);
	}
}
