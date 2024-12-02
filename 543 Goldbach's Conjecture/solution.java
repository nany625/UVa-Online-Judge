import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 999999;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
    static ArrayList<Integer> primes = new ArrayList<>();
	public static void main(String[] args) throws IOException {
    	for(int i = 3; i <= MAX_NUM; i += 2) {
            if(!isComposite[i]) {
                primes.add(i);
                if(i <= 999) {
                    for(int j = i * i; j <= MAX_NUM; j += i << 1)
                        isComposite[j] = true;
                }
            }
        }
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
    	int n;
    	StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0) {
	        int i = 0;
	        while(isComposite[n - primes.get(i)])
	            ++i;
	        output.append(n).append(" = ").append(primes.get(i)).append(" + ").append(n - primes.get(i)).append('\n');
    	}
	    System.out.print(output);
	}
}
