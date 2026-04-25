import java.io.*;
import java.math.*;

public class Main {
    static BigInteger MOD = new BigInteger("1000000007");
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int t = (int)st.nval;
		StringBuilder output = new StringBuilder();
		int N;
		for(int i = 1; i <= t; ++i) {
		    st.nextToken();
		    BigInteger n = new BigInteger("" + (long)st.nval);
		    BigInteger startRow = n.divide(new BigInteger("2")).add(BigInteger.ONE);
		    BigInteger rows = n.subtract(startRow).add(BigInteger.ONE);
		    BigInteger cols = rows;
		    if(n.mod(new BigInteger("2")).compareTo(BigInteger.ZERO) == 0)
		        cols = cols.add(BigInteger.ONE);
		    BigInteger topLeft = startRow.multiply(startRow.subtract(BigInteger.ONE)).divide(new BigInteger("2")).add(BigInteger.ONE);
		    BigInteger topRight = topLeft.add(startRow).subtract(BigInteger.ONE);
		    BigInteger sum1 = (topLeft.add(topRight)).multiply(cols).divide(new BigInteger("2"));
		    output.append("Case #").append(i).append(": ").append(rows.multiply(sum1).add   ((  (rows.multiply(rows.subtract(BigInteger.ONE)).divide(new BigInteger("2")).multiply(startRow) .add( (rows.subtract(BigInteger.ONE)).multiply(rows).multiply(rows.add(BigInteger.ONE)).divide(new BigInteger("6")))))  .multiply(cols))    .mod(MOD)).append('\n');
		}
		System.out.print(output);
	}
}
