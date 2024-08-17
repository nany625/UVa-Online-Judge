import java.io.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BigInteger[] fac = new BigInteger[1001];
	    fac[0] = fac[1] = BigInteger.ONE;
	    for(int i = 2; i <= 1000; ++i)
	        fac[i] = fac[i - 1].multiply(new BigInteger("" + i));
    	StreamTokenizer st = new StreamTokenizer(System.in);
    	StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER)
	        output.append((int)st.nval + "!\n" + fac[(int)st.nval] + "\n");
	    System.out.print(output);
	}
}
