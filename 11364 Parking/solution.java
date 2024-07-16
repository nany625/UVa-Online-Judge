import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		st.nextToken();
		int t = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(t-- > 0) {
		    st.nextToken();
		    int n = (int)st.nval, min = 99, max = 0;
		    while(n-- > 0) {
		        st.nextToken();
		        min = Math.min(min, (int)st.nval);
		        max = Math.max(max, (int)st.nval);
		    }
		    output.append(2 * (max - min) + "\n");
		}
		System.out.print(output);
	}
}
