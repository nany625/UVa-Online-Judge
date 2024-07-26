import java.io.*;

public class Main {
	static short[] primes = new short[1229], primesSumCount = new short[10001];
	static int count = 1;
	public static void main(String[] args) throws IOException {
    	primes[0] = 2;
    	for(short i = 3; count < 1229; i += 2) {
            if(isPrime(i))
                primes[count++] = i;
        }
	    for(int i = 0; i < 1229; ++i) {
            int sum = 0;
            for(int j = i; j < 1229 && (sum += primes[j]) <= 10000; ++j)
                ++primesSumCount[sum];
        }
    	StreamTokenizer st = new StreamTokenizer(System.in);
    	int num;
    	StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER && (num = (int)st.nval) != 0)
	        output.append(primesSumCount[num] + "\n");
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
