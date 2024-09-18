import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int X = 0, N;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) >= 0)
            output.append("Case ").append(++X).append(": ").append((int)Math.ceil(Math.log(N) / Math.log(2))).append('\n');
        System.out.print(output);
	}
}
