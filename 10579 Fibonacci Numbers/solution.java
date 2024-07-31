// #解法一
import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    char[][] fib = new char[4787][];
		fib[0] = new char[1];
		fib[0][0] = '0';
		fib[1] = new char[1];
		fib[1][0] = '1';
		short[] digits = new short[4787];
		digits[0] = digits[1] = 1;
		for(int i = 2; i <= 4786; ++i) {
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
            for(int i = digits[number] - 1; i >= 0; --i)
                output.append(fib[number][i]);
            output.append("\n");
        }
		System.out.print(output);
	}
}

// #解法二
import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws IOException {
        ArrayList<BigInteger> fib = new ArrayList<>();
		fib.add(BigInteger.ZERO);
		fib.add(BigInteger.ONE);
		StreamTokenizer st = new StreamTokenizer(System.in);
		StringBuilder output = new StringBuilder();
		while((st.nextToken()) == st.TT_NUMBER) {
		    int number = (int)st.nval;
    		if(number >= fib.size()) {
    			for(int i = fib.size(); i <= number; ++i)
			        fib.add(fib.get(i - 1).add(fib.get(i - 2)));
    		}
		    output.append(fib.get(number) + "\n");
		}
		System.out.print(output);
	}
}
