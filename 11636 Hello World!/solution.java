import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        int X = 0, N;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) >= 0)
            output.append("Case " + (++X) + ": " + (int)Math.ceil(Math.log(N) / Math.log(2)) + "\n");
        System.out.print(output);
	}
}
