import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    static ArrayList<BigInteger> fib = new ArrayList<>();
	public static void main(String[] args) throws IOException {
	    fib.add(BigInteger.ONE);
	    fib.add(new BigInteger("2"));
	    for(int n = 2; n <= 100; ++n)
	        fib.add(fib.get(n - 2).add(fib.get(n - 1)));
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s1;
        boolean firstCase = true;
        StringBuilder output = new StringBuilder();
        while((s1 = br.readLine()) != null) {
            if(!firstCase)
                output.append('\n');
            String s2 = br.readLine();
            if(s1.equals("0") && s2.equals("0"))
                output.append("0\n");
            else {
                BigInteger sum = fibToInt(s1).add(fibToInt(s2));
                boolean leadingZero = true;
                for(int i = fib.size() - 1; i >= 0; --i) {
                    if(sum.compareTo(fib.get(i)) >= 0) {
                        output.append('1');
                        sum = sum.subtract(fib.get(i));
                        leadingZero = false;
                    } else if(!leadingZero)
                        output.append('0');
                }
                output.append('\n');
            }
            br.readLine();
            firstCase = false;
        }
        System.out.print(output);
	}
	
	static BigInteger fibToInt(String s) {
	    BigInteger ans = BigInteger.ZERO;
	    for(int i = s.length() - 1; i >= 0; --i) {
	        if(s.charAt(i) == '1')
	            ans = ans.add(fib.get(s.length() - 1 - i));
	    }
	    return ans;
	}
}
