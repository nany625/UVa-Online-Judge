import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		st.nextToken();
		int n = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(n-- > 0) {
		    st.nextToken();
		    int x = (int)st.nval;
		    st.nextToken();
		    int y = (int)st.nval;
		    if(x == y)
		        output.append("0\n");
		    else {
		        int maxLen = (int)Math.sqrt(y - x);
		        if(maxLen == Math.sqrt(y - x))
    				output.append(2 * maxLen - 1).append('\n');
    			else if(maxLen < Math.sqrt(y - x - maxLen))
    				output.append(2 * maxLen + 1).append('\n');
    			else
    				output.append(2 * maxLen).append('\n');
		    }
		}
		System.out.print(output);
	}
}
