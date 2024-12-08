import java.io.*;

public class Main {
    static short MAX_NUM = 1000;
    static short[] primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}, table = new short[MAX_NUM + 1];
	public static void main(String[] args) throws IOException {
        for(short i = 1; i <= MAX_NUM; ++i) {
            short temp = factorSum(i);
            if(temp <= MAX_NUM)
                table[temp] = i;
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int cases = 0, S;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (S = (int)st.nval) != 0)
	        output.append("Case ").append(++cases).append(": ").append(table[S] == 0 ? -1 : table[S]).append('\n');
        System.out.print(output);
	}
	
	static short factorSum(short n) {
        short sum = 1, limit = (short)Math.sqrt(n), temp = n;
        for(int i = 0; i < 11 && primes[i] <= limit; ++i) {
            if(n % primes[i] == 0) {
                short tempSum = 1, term = 1;
                do {
                    tempSum += term *= primes[i];
                    n /= primes[i];
                } while(n % primes[i] == 0);
                sum *= tempSum;
                limit = (short)Math.sqrt(n);
            }
        }
        if(n > 1)
            sum *= (1 + n);
        return sum;
    }
}
