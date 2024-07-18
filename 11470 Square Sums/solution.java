import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        int cases = 0, n;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
            int squares = (n + 1) / 2;
            short[] sum = new short[squares];
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    st.nextToken();
                    sum[Math.min(Math.min(Math.min(i, j), n - 1 - i), n - 1 -j)] += (int)st.nval;
                }
            }
            output.append("Case " + (++cases) + ":");
            for(Short s : sum)
                output.append(" " + s);
            output.append("\n");
        }
        System.out.print(output);
	}
}
