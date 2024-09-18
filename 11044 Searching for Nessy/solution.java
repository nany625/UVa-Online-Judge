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
            int n = (int)st.nval;
            st.nextToken();
            output.append((n / 3) * ((int)st.nval / 3)).append('\n');
        }
        System.out.print(output);
	}
}
