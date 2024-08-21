import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        int[] Mondays = {3, 0, 0, 4, 2, 6, 4, 1, 5, 3, 0, 5};
        String[] s = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
        StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int cases = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(cases-- > 0) {
            st.nextToken();
            int M = (int)st.nval;
            st.nextToken();
            int D = (int)st.nval;
    	    output.append(s[(D + 7 - Mondays[M - 1]) % 7]).append('\n');
        }
        System.out.print(output);
	}
}
