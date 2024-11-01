import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
	    StringBuilder output = new StringBuilder();
	    while(st.nextToken() == StreamTokenizer.TT_WORD) {
	        String s = st.sval;
	        st.nextToken();
	        String t = st.sval;
            int i = 0, j = 0;
	        while(j < t.length()) {
		        if(s.charAt(i) == t.charAt(j))
		            ++i;
    	        if(i == s.length()) {
    	            output.append("Yes\n");
    	            break;
    	        }
    	        ++j;
    	    }
    	    if(i < s.length())
    	        output.append("No\n");
	    }
	    System.out.print(output);
	}
}
