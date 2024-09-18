import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int T = (int)st.nval;
        StringBuilder output = new StringBuilder();
        for(int i = 1; i <= T; ++i) {
            st.nextToken();
            long n = (long)st.nval, numerator = n * (n - 1);
            if((numerator & 3) != 0)
                output.append("Case ").append(i).append(": ").append(numerator >> 1).append("/2\n");
            else
                output.append("Case ").append(i).append(": ").append(numerator >> 2).append('\n');
        }
        System.out.print(output);
	}
}
