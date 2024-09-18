import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
	    StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int n = (int)st.nval, x = 0, remainder = 0;
            do {
                remainder = (10 * remainder + 1) % n;
                ++x;
            } while(remainder != 0);
            output.append(x).append('\n');
        }
        System.out.print(output);
	}
}
