import java.io.*;
import java.math.*;

public class Main {
	public static void main (String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String line;
		BigInteger ans = BigInteger.ZERO;
		while((line = br.readLine()) != null && !line.equals("0"))
		    ans = ans.add(new BigInteger(line));
		System.out.println(ans);
	}
}
