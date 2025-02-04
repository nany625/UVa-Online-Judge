import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int k = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(k-- > 0) {
            st.nextToken();
            String S = st.sval;
            st.nextToken();
            int q = (int)st.nval;
            while(q-- > 0) {
                st.nextToken();
                output.append(S.contains(st.sval) ? "y\n" : "n\n");
            }
        }
		System.out.print(output);
	}
}
