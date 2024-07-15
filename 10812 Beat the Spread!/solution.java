import java.io.*;

public class Main {
	public static void main (String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		st.nextToken();
		int n = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(n-- > 0) {
		    st.nextToken();
    		int s = (int)st.nval;
    		st.nextToken();
    		int d = (int)st.nval;
    		if(s < d || (s + d) % 2 == 1)
    		    output.append("impossible\n");
    		else
    		    output.append((s + d) / 2 + " " + (s - d) / 2 + "\n");
		}
		System.out.print(output);
	}
}
