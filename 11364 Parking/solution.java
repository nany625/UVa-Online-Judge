import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
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
		    output.append(max - min << 1).append('\n');
		}
		System.out.print(output);
	}
}
