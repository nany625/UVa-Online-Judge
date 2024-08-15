import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int cases = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(cases-- > 0) {
    	    st.nextToken();
    	    output.append((int)st.nval % 3 == 1 ? "NO\n" : "YES\n");
    	}
        System.out.print(output);
	}
}
