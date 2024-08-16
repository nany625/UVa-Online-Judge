import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
        for(int i = 1; i <= T; ++i) {
            st.nextToken();
            long n = (long)st.nval, numerator = n * (n - 1);
            if(numerator % 4 == 0)
                output.append("Case " + i + ": " + numerator / 4 + "\n");
            else
                output.append("Case " + i + ": " + numerator / 2 + "/2\n");
        }
        System.out.print(output);
	}
}
