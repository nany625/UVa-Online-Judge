import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int T = (int)st.nval;
		StringBuilder output = new StringBuilder();
		while(T-- > 0) {
		    st.nextToken();
		    long n = (long)st.nval;
		    output.append(((long)(1 + Math.sqrt(1 + (n << 3))) >> 1) - 1).append('\n');
		}
        System.out.print(output);
	}
}
