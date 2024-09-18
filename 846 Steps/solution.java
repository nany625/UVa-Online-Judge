import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
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
    				output.append((maxLen << 1) - 1).append('\n');
    			else if(maxLen < Math.sqrt(y - x - maxLen))
    				output.append((maxLen << 1) + 1).append('\n');
    			else
    				output.append(maxLen << 1).append('\n');
		    }
		}
		System.out.print(output);
	}
}
