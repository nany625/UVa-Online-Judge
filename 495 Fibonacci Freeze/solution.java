// #解法一
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    char[][] fib = new char[5001][];
		fib[0] = new char[1];
		fib[0][0] = '0';
		fib[1] = new char[1];
		fib[1][0] = '1';
		short[] digits = new short[5001];
		digits[0] = digits[1] = 1;
		for(int i = 2; i <= 5000; ++i) {
		    fib[i] = new char[digits[i - 1] + 1];
            Arrays.fill(fib[i], '0');
            short j;
            for(j = 0; j < digits[i - 1]; ++j) {
            	fib[i][j + 1] += (fib[i][j] + fib[i - 1][j] + fib[i - 2][j] - 3 * '0') / 10;
            	fib[i][j] = (char)((fib[i][j] + fib[i - 1][j] + fib[i - 2][j] - 3 * '0') % 10 + '0');
            }
            digits[i] = (short)(j + (fib[i][j] - '0'));
        }
        StreamTokenizer st = new StreamTokenizer(System.in);
        StringBuilder output = new StringBuilder();
        while((st.nextToken()) == st.TT_NUMBER) {
            int number = (int)st.nval;
            output.append("The Fibonacci number for ").append(number).append(" is ");
            for(int i = digits[number] - 1; i >= 0; --i)
                output.append(fib[number][i]);
            output.append('\n');
        }
		System.out.print(output);
	}
}

// #解法二
import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws IOException {
        BigInteger[] fib = new BigInteger[5001];
		fib[0] = BigInteger.ZERO;
		fib[1] = BigInteger.ONE;
		for(int i = 2; i <= 5000; ++i)
		    fib[i] = fib[i - 1].add(fib[i - 2]);
		StreamTokenizer st = new StreamTokenizer(System.in);
		StringBuilder output = new StringBuilder();
		while((st.nextToken()) == st.TT_NUMBER)
		    output.append("The Fibonacci number for ").append((int)st.nval).append(" is ").append(fib[(int)st.nval]).append('\n');
		System.out.print(output);
	}
}
