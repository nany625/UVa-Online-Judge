import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int T = (int)st.nval;
		StringBuilder output = new StringBuilder();
		for(int i = 1; i <= T; ++i) {
		    st.nextToken();
    		int L = (int)st.nval;
    		st.nextToken();
    		int W = (int)st.nval;
    		st.nextToken();
    		int H = (int)st.nval;
    		output.append("Case ").append(i).append(L <= 20 && W <= 20 && H <= 20 ? ": good\n" : ": bad\n");
		}
		System.out.print(output);
	}
}
