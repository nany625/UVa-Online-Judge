import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
        StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_WORD) {
    	    String encryption = st.sval;
    	    st.nextToken();
    	    String origin = st.sval;
    	    int[][] frequency = new int[2][26];
    	    int len = encryption.length();
    	     for(int i = 0; i < len; ++i) {
    	        ++frequency[0][encryption.charAt(i) - 'A'];
    			++frequency[1][origin.charAt(i) - 'A'];
    	    }
    	    Arrays.sort(frequency[0]);
    	    Arrays.sort(frequency[1]);
    		output.append(Arrays.equals(frequency[0], frequency[1]) ? "YES\n" : "NO\n");
    	}
        System.out.print(output);
	}
}
