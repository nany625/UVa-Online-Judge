import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            double L = st.nval;
            st.nextToken();
            double W = st.nval;
            output.append(String.format("%.3f 0.000 %.3f\n", (L + W - Math.sqrt(L * L + W * W - L * W)) / 6, Math.min(L, W) / 2));
        }
        System.out.print(output);
	}
}
