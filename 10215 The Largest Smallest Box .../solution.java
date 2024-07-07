import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            double L = st.nval;
            st.nextToken();
            double W = st.nval;
            output.append(String.format("%.3f 0.000 %.3f\n", (L + W - Math.sqrt(L * L + W * W - L * W)) / 6, (L > W ? W : L) / 2));
        }
        System.out.print(output);
	}
}
