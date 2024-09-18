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
            int m = (int)st.nval;
            if((n - m) % (m - 1) == 0)
                output.append((n - m) / (m - 1) + 1).append('\n');
            else
                output.append("cannot do this\n");
        }
        System.out.print(output);
	}
}
