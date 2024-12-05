import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_WORD) {
    	    String encryption = st.sval;
    	    st.nextToken();
    	    String origin = st.sval;
    	    int[][] frequency = new int[2][26];
    	    for(int i = 0; i < encryption.length(); ++i) {
    	        ++frequency[0][encryption.charAt(i) - 'A'];
    			++frequency[1][origin.charAt(i) - 'A'];
    	    }
    	    Arrays.sort(frequency[0]);
    	    Arrays.sort(frequency[1]);
    	    int i = 25;
    	    while(i >= 0 && frequency[0][i] == frequency[1][i] && frequency[0][i] > 0)
    	        --i;
    		output.append(i < 0 || frequency[0][i] == frequency[1][i] ? "YES\n" : "NO\n");
    	}
        System.out.print(output);
	}
}
