import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    int N = (int)st.nval;
		    st.nextToken();
		    BigInteger A = new BigInteger("" + (int)st.nval);
		    BigInteger sum = BigInteger.ZERO;
		    do {
		        sum = sum.add(new BigInteger("" + N).multiply(A.pow(N)));
		    } while(N-- > 0);
		    output.append(sum).append('\n');
		}
		System.out.print(output);
	}
}
