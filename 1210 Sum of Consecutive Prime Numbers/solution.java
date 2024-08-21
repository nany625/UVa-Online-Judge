import java.io.*;

public class Main {
    static boolean[] isComposite = new boolean[10001];
	static short[] primes = new short[1229], primesSumCount = new short[10001];
	static int count = 1;
	public static void main(String[] args) throws IOException {
    	primes[0] = 2;
    	for(short i = 3; count < 1229; i += 2) {
            if(!isComposite[i]) {
                primes[count++] = i;
                if(i <= 100) {
                    for(int j = i * i; j <= 10000; j += i)
                        isComposite[j] = true;
                }
            }
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
	        output.append(primesSumCount[num]).append('\n');
	    System.out.print(output);
	}
}
