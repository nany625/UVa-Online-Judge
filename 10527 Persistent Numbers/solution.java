import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws IOException {
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s;
        StringBuilder output = new StringBuilder();
        while((s = br.readLine()) != null && !s.equals("-1")) {
            if(s.length() == 1)
                output.append('1').append(s).append('\n');
            else {
                ArrayList<Integer> digits = new ArrayList<>();
                BigInteger n = new BigInteger(s);
                BigInteger temp = new BigInteger("9");
                while(!temp.equals(BigInteger.ONE)) {
                    if(n.mod(temp).equals(BigInteger.ZERO)) {
                        digits.add(temp.intValue());
                        n = n.divide(temp);
                    } else
                        temp = temp.subtract(BigInteger.ONE);
                }
                if(n.equals(BigInteger.ONE)) {
                    for(int i = digits.size() - 1; i >= 0; --i)
                        output.append(digits.get(i));
                    output.append('\n');
                } else
                    output.append("There is no such number.\n");
            }
        }
        System.out.print(output);
	}
}
