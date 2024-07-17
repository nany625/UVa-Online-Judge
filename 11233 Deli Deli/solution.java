import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int L = (int)st.nval;
        st.nextToken();
        int N = (int)st.nval;
        HashMap<String, String> irregular = new HashMap<>();
        while(L-- > 0) {
            st.nextToken();
            String word = st.sval;
            st.nextToken();
            irregular.put(word, st.sval);
        }
        StringBuilder output = new StringBuilder();
        while(N-- > 0) {
            st.nextToken();
            String word = st.sval;
            if(irregular.containsKey(word))
                output.append(irregular.get(word) + "\n");
            else {
                int len = word.length();
                if(word.endsWith("y")) {
        			if(word.charAt(len - 2) == 'a' || word.charAt(len - 2) == 'e' || word.charAt(len - 2) == 'i' || word.charAt(len - 2) == 'o' || word.charAt(len - 2) == 'u')
        				output.append(word + "s\n");
        			else
        				output.append(word.substring(0, len - 1) + "ies\n");
        		}
        		else if(word.endsWith("o") || word.endsWith("s") || word.endsWith("ch") || word.endsWith("sh") || word.endsWith("x"))
        			output.append(word + "es\n");
        		else
        			output.append(word + "s\n");
            }
        }
        System.out.print(output);
	}
}