import java.io.*;

public class Main {
	public static void main (String[] args) throws IOException {
		StreamTokenizer st = new StreamTokenizer(System.in);
		st.nextToken();
		int N = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(N-- > 0) {
		    st.nextToken();
		    double D = st.nval;
		    st.nextToken();
		    double L = st.nval;
		    output.append(String.format("%.3f\n", L * Math.sqrt(L * L - D * D) * Math.PI / 4));
		}
		System.out.print(output);
	}
}
