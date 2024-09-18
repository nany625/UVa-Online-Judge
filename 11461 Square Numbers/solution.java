import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int a, b;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (a = (int)st.nval) != 0 && st.nextToken() == StreamTokenizer.TT_NUMBER && (b = (int)st.nval) != 0)
    		output.append((int)Math.sqrt(b) - (int)Math.ceil(Math.sqrt(a)) + 1).append('\n');
        System.out.print(output);
	}
}
