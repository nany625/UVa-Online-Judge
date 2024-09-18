import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int S = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(S-- > 0) {
            st.nextToken();
            int N = (int)st.nval;
            st.nextToken();
            double p = st.nval;
            st.nextToken();
            int I = (int)st.nval;
            output.append(String.format("%.4f\n", p > 0 ? p * Math.pow(1 - p, I - 1) / (1 - Math.pow(1 - p, N)) : p));
        }
        System.out.print(output);
	}
}
