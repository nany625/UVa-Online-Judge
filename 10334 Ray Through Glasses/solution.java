// #解法一
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    char[][] fib = new char[1001][];
		fib[0] = new char[1];
		fib[0][0] = '1';
		fib[1] = new char[1];
		fib[1][0] = '2';
		short[] digits = new short[1001];
		digits[0] = digits[1] = 1;
		for(int i = 2; i <= 1000; ++i) {
		    fib[i] = new char[digits[i - 1] + 1];
            Arrays.fill(fib[i], '0');
            short j;
            for(j = 0; j < digits[i - 1]; ++j) {
            	fib[i][j + 1] += (fib[i][j] + fib[i - 1][j] + fib[i - 2][j] - 3 * '0') / 10;
            	fib[i][j] = (char)((fib[i][j] + fib[i - 1][j] + fib[i - 2][j] - 3 * '0') % 10 + '0');
            }
            digits[i] = (short)(j + (fib[i][j] - '0'));
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int number = (int)st.nval;
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
        BigInteger[] fib = new BigInteger[4787];
		fib[0] = BigInteger.ONE;
		fib[1] = fib[0].add(fib[0]);
		for(int i = 2; i <= 1000; ++i)
		    fib[i] = fib[i - 1].add(fib[i - 2]);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER)
		    output.append(fib[(int)st.nval]).append('\n');
		System.out.print(output);
	}
}

// #解法三
import java.io.*;
import java.math.*;

public class Main {
    static BigInteger[][] temp = new BigInteger[2][2];
	public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER)
            output.append(powerMatrix(new BigInteger[][]{{BigInteger.ONE, BigInteger.ONE}, {BigInteger.ONE, BigInteger.ZERO}}, (int)st.nval + 1)).append('\n');
        System.out.print(output);
	}
	
	static void multiplyMatrix(BigInteger[][] a, BigInteger[][] b) {
	    temp[0][0] = a[0][0].multiply(b[0][0]).add(a[0][1].multiply(b[1][0]));
	    temp[0][1] = a[0][0].multiply(b[0][1]).add(a[0][1].multiply(b[1][1]));
	    temp[1][0] = a[1][0].multiply(b[0][0]).add(a[1][1].multiply(b[1][0]));
	    temp[1][1] = a[1][0].multiply(b[0][1]).add(a[1][1].multiply(b[1][1]));
	    a[0][0] = temp[0][0];
	    a[0][1] = temp[0][1];
	    a[1][0] = temp[1][0];
	    a[1][1] = temp[1][1];
	}
	
	static BigInteger powerMatrix(BigInteger[][] matrix, int n) {
	    BigInteger[][] result = {{BigInteger.ONE, BigInteger.ZERO}, {BigInteger.ZERO, BigInteger.ONE}};
	    while(n > 0) {
	        if((n & 1) == 1)
	            multiplyMatrix(result, matrix);
	        multiplyMatrix(matrix, matrix);
	        n >>= 1;
	    }
	    return result[0][0];
	}
}
