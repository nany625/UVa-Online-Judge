// #解法一
import java.util.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
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
        while(sc.hasNextInt()) {
            int number = sc.nextInt();
            System.out.println("The Fibonacci number for " + number + " is " + new StringBuilder(new String(fib[number], 0, digits[number])).reverse());
        }
		sc.close();
	}
}

// #解法二
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		ArrayList<BigInteger> fib = new ArrayList<>();
		fib.add(BigInteger.ZERO);
		fib.add(BigInteger.ONE);
		while(sc.hasNextInt()) {
		    int number = sc.nextInt();
		    System.out.print("The Fibonacci number for " + number + " is ");
    		if(number >= fib.size()) {
    			for(int i = fib.size(); i <= number; ++i)
			        fib.add(fib.get(i - 1).add(fib.get(i - 2)));
    		}
		    System.out.println(fib.get(number));
		}
		sc.close();
	}
}
