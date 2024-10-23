import java.io.*;

public class Main {
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int n = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(n-- > 0) {
		    st.nextToken();
    		int s = (int)st.nval;
    		st.nextToken();
    		int d = (int)st.nval;
    		if(s < d || (((s + d) & 1) == 1))
    		    output.append("impossible\n");
    		else
    		    output.append(s + d >> 1).append(' ').append(s - d >> 1).append('\n');
		}
		System.out.print(output);
	}
}
