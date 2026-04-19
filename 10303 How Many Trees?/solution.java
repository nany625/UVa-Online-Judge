import java.io.*;
import java.math.*;

public class Main {
    static BigInteger[] ans = new BigInteger[1001];
	public static void main(String[] args) throws IOException {
		ans[1] = BigInteger.ONE;
		for(int i = 2; i <= 1000; ++i)
		    ans[i] = ans[i - 1].multiply(new BigInteger("" + ((i << 2) - 2))).divide(new BigInteger("" + (i + 1)));
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER)
		    output.append(ans[(int)st.nval]).append('\n');
		System.out.print(output);
	}
}
