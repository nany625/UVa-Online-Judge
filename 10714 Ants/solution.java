import java.io.*;
import java.util.*;

public class Main {
	public static void main (String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		st.nextToken();
		int cases = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(cases-- > 0) {
		    st.nextToken();
    		int l = (int)st.nval;
    		st.nextToken();
    		int n = (int)st.nval, min = 0, max = 0;
    		for(int i = 0; i < n; ++i) {
    		    st.nextToken();
    		    int pos = (int)st.nval;
    		    min = Math.max(min, Math.min(pos, l - pos));
                max = Math.max(max, Math.max(pos, l - pos));
    		}
            output.append(min).append(' ').append(max).append('\n');
		}
		System.out.print(output);
	}
}
