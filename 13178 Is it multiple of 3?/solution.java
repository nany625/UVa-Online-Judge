import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
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
