import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 32765;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
    static ArrayList<Short> primes = new ArrayList<>();
    static short[] pairs = new short[16382];
	public static void main(String[] args) throws IOException {
    	for(short i = 3; i <= MAX_NUM; i += 2) {
            if(!isComposite[i]) {
    	        primes.add(i);
                if(i <= 181) {
                    for(int j = i * i; j <= MAX_NUM; j += i)
                        isComposite[j] = true;
                }
    	    }
        }
        pairs[0] = 1;
        for(int i = 0; i < primes.size(); ++i) {
            for(int j = i; j < primes.size(); ++j) {
                int sum = primes.get(i) + primes.get(j);
                if(sum < 32768)
                    ++pairs[(sum >> 1) - 2];
            }
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int n;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (n = (int)st.nval) != 0)
    		output.append(pairs[(n >> 1) - 2]).append('\n');
	    System.out.print(output);
	}
}
