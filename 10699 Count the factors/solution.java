import java.io.*;
import java.util.*;

public class Main {
    static short MAX_NUM = 1000;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
    static ArrayList<Short> primes = new ArrayList<>();
	public static void main (String[] args) throws IOException {
		primes.add((short)2);
    	for(short i = 3; i <= MAX_NUM; i += 2) {
    		if(!isComposite[i]) {
    		    primes.add(i);
    		    if(i <= 31) {
    	            for(int j = i * i; j <= MAX_NUM; j += i)
    	                isComposite[j] = true;
    	        }
    		}
    	}
    	int size = primes.size();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int num;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (num = (int)st.nval) != 0) {
		    output.append(num).append(" : ");
		    short limit = (short)Math.sqrt(num);
		    int pfCount = 0;
		    for(int i = 0; i < size && primes.get(i) <= limit; ++i) {
		        if(num % primes.get(i) == 0) {
                    ++pfCount;
                    do {
                        num /= primes.get(i);
                    } while(num % primes.get(i) == 0);
                    limit = (short)Math.sqrt(num);
		        }
		    }
		    output.append(pfCount + (num > 1 ? 1 : 0)).append('\n');
		}
		System.out.print(output);
	}
}
