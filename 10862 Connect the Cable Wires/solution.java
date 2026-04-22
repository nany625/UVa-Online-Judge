import java.io.*;
import java.math.*;

public class Main {
    static BigInteger[] fib = new BigInteger[2001];
	public static void main(String[] args) throws IOException {
	    fib[0] = BigInteger.ZERO;
		fib[1] = BigInteger.ONE;
		for(int i = 2; i <= 2000; ++i)
		    fib[i] = fib[i - 1].multiply(new BigInteger("3")).subtract(fib[i - 2]);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		StringBuilder output = new StringBuilder();
		int N;
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) != 0)
		    output.append(fib[N]).append('\n');
		System.out.print(output);
	}
}
