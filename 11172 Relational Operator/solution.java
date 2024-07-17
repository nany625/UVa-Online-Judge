import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int t = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(t-- > 0) {
            st.nextToken();
            int a = (int)st.nval;
            st.nextToken();
            int b = (int)st.nval;
            output.append(a < b ? "<\n" : a > b ? ">\n" : "=\n");
        }
        System.out.print(output);
	}
}
