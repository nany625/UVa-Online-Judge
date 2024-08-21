import java.io.*;

public class Main {
    static boolean[] isComposite = new boolean[998];
    static short[] primes = new short[168];
    static int count = 1;
	public static void main (String[] args) throws IOException {
		primes[0] = 2;
		for(short i = 3; count < 168; i += 2) {
            if(!isComposite[i]) {
                primes[count++] = i;
                if(i <= 31) {
                    for(short j = (short)(i * i); j <= 997; j += i)
                        isComposite[j] = true;
                }
            }
        }
		StreamTokenizer st = new StreamTokenizer(System.in);
		int num;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (num = (int)st.nval) != 0) {
		    output.append(num + " : ");
		    short limit = (short)Math.sqrt(num);
		    int pfCount = 0;
		    for(int i = 0; i < 168 && primes[i] <= limit; ++i) {
		        if(num % primes[i] == 0) {
                    ++pfCount;
                    do {
                        num /= primes[i];
                    } while(num % primes[i] == 0);
                    limit = (short)Math.sqrt(num);
		        }
		    }
		    output.append(pfCount + (num > 1 ? 1 : 0)).append('\n');
		}
		System.out.print(output);
	}
	
	static boolean isPrime(short n) {
        short limit = (short)Math.sqrt(n);
        for(int i = 1; i < count && primes[i] <= limit; ++i) {
            if(n % primes[i] == 0)
                return false;
        }
        return true;
    }
}
