import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int n;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
            int a = 0, b = 0, count = 0, term = 1;
            while(n > 0) {
                if((n & 1) == 1) {
                    if((count & 1) == 0)
                        a += term;
                    else
                        b += term;
                    ++count;
                }
                n >>= 1;
                term <<= 1;
            }
            output.append(a).append(' ').append(b).append('\n');
        }
	    System.out.print(output);
	}
}
