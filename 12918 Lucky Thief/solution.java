import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
    	while(T-- > 0) {
    	    st.nextToken();
            int n = (int)st.nval;
            st.nextToken();
		    output.append((long)(2 * (int)st.nval - n - 1) * n / 2 + "\n");
    	}
        System.out.print(output);
	}
}
