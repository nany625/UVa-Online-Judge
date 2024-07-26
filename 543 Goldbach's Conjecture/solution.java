import java.io.*;

public class Main {
    static boolean[] isComposite = new boolean[1000000];
    static int[] primes = new int[78497];
    static int count = 0;
	public static void main(String[] args) throws IOException {
    	for(int i = 3; i <= 999999; i += 2) {
            if(!isComposite[i]) {
                primes[count++] = i;
                if(i <= 999) {
                    for(int j = i * i; j <= 999999; j += i)
                        isComposite[j] = true;
                }
            }
        }
    	StreamTokenizer st = new StreamTokenizer(System.in);
    	int n;
    	StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
	        int i = 0;
	        while(isComposite[n - primes[i]])
	            ++i;
	        output.append(n + " = " + primes[i] + " + " + (n - primes[i]) + "\n");
    	}
	    System.out.print(output);
	}
}
