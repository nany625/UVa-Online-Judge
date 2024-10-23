import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int S = (int)st.nval;
            st.nextToken();
            output.append((int)Math.ceil((-1 + Math.sqrt(1 + ((S * S - S + ((long)st.nval << 1)) << 2))) / 2)).append('\n');
		}
        System.out.print(output);
	}
}
