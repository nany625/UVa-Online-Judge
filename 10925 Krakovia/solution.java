import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int cases = 0, N, F;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0 && st.nextToken() == StreamTokenizer.TT_NUMBER && (F = (int)st.nval) != 0) {
		    BigInteger sum = BigInteger.ZERO;
		    while(N-- > 0)
		        sum = sum.add(new BigInteger(br.readLine()));
            output.append("Bill #" + (++cases) + " costs " + sum + ": each friend should pay " + sum.divide(new BigInteger("" + F)) + "\n\n");
		}
		System.out.print(output);
	}
}
