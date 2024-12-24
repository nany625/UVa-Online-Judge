import java.io.*;
import java.math.*;

public class Main {
    static int MAX_FACTORIAL_SIZE = 366;
    static BigInteger[] fac = new BigInteger[MAX_FACTORIAL_SIZE + 1];
	public static void main(String[] args) throws IOException {
		initFactorial();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int n;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
		    output.append(n).append("! --\n");
		    int[] count = new int[10];
		    countDigits(count, fac[n]);
		    for(int i = 0; i < 10; ++i) {
		        if(i % 5 == 0)
                    output.append(String.format("   (%d)%5d", i, count[i]));
                else if(i % 5 == 4)
                    output.append(String.format("    (%d)%5d\n", i, count[i]));
                else
                    output.append(String.format("    (%d)%5d", i, count[i]));
		    }
		}
		System.out.print(output);
	}
	
	static void initFactorial() {
	    fac[0] = fac[1] = BigInteger.ONE;
	    for(int i = 2; i <= MAX_FACTORIAL_SIZE; ++i)
	        fac[i] = fac[i - 1].multiply(new BigInteger("" + i));
	}
	
	static void countDigits(int[] array, BigInteger n) {
	    while(n != BigInteger.ZERO) {
	        ++array[n.mod(BigInteger.TEN).intValue()];
	        n = n.divide(BigInteger.TEN);
	    }
	}
}
