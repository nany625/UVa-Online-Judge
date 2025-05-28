import java.io.*;
import java.math.*;

public class Main {
    static BigInteger[] ans  = new BigInteger[801];
	public static void main(String[] args) throws IOException {
        ans[1] = BigInteger.ZERO;
        ans[2] = BigInteger.ONE;
        for(int n = 3; n <= 800; ++n)
        	ans[n] = new BigInteger("" + (n - 1)).multiply(ans[n - 2].add(ans[n - 1]));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        int n;
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != -1)
            output.append(ans[n]).append('\n');
	    System.out.print(output);
	}
}
