import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int T = (int)st.nval, total = 0;
		StringBuilder output = new StringBuilder();
		while(T-- > 0) {
		    st.nextToken();
		    if(st.sval.equals("donate")) {
		        st.nextToken();
		        total += (int)st.nval;
		    } else
		        output.append(total).append('\n');
		}
		System.out.print(output);
	}
}
