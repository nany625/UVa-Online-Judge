import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
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
                output.append(irregular.get(word)).append('\n');
            else {
                if(word.endsWith("y")) {
        			if(word.charAt(word.length() - 2) == 'a' || word.charAt(word.length() - 2) == 'e' || word.charAt(word.length() - 2) == 'i' || word.charAt(word.length() - 2) == 'o' || word.charAt(word.length() - 2) == 'u')
        				output.append(word).append("s\n");
        			else
        				output.append(word.substring(0, word.length() - 1)).append("ies\n");
        		}
        		else if(word.endsWith("o") || word.endsWith("s") || word.endsWith("ch") || word.endsWith("sh") || word.endsWith("x"))
        			output.append(word).append("es\n");
        		else
        			output.append(word).append("s\n");
            }
        }
        System.out.print(output);
	}
}
