import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
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
