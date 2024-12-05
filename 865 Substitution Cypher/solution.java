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
    	while(cases-- > 0) {
    	    String plaintext = br.readLine(), substitution = br.readLine();
    	    output.append(substitution).append('\n').append(plaintext).append('\n');
    	    HashMap<Character, Character> cypher = new HashMap<>();
    	    for(int i = 0; i < plaintext.length(); ++i)
    	        cypher.put(plaintext.charAt(i), substitution.charAt(i));
    	    String text;
    	    while((text = br.readLine()) != null && !text.isEmpty()) {
    	        for(int i = 0; i < text.length(); ++i)
    	            output.append(cypher.containsKey(text.charAt(i)) ? (char)cypher.get(text.charAt(i)) : text.charAt(i));
    	        output.append('\n');
    	    }
    	    if(cases > 0)
    	        output.append('\n');
    	}
        System.out.print(output);
	}
}
