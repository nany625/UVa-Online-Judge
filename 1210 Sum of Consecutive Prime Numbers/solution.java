import java.io.*;
import java.util.*;

public class Main {
    static short MAX_NUM = 10000;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
    static ArrayList<Short> primes = new ArrayList<>();
	static short[] primesSumCount = new short[MAX_NUM + 1];
	public static void main(String[] args) throws IOException {
    	primes.add((short)2);
    	for(short i = 3; i <= MAX_NUM; i += 2) {
    		if(!isComposite[i]) {
    		    primes.add(i);
    		    if(i <= 100) {
    	            for(int j = i * i; j <= MAX_NUM; j += i)
    	                isComposite[j] = true;
    	        }
    		}
    	}
    	int size = primes.size();
	    for(int i = 0; i < size; ++i) {
            int sum = 0;
            for(int j = i; j < size && (sum += primes.get(j)) <= MAX_NUM; ++j)
                ++primesSumCount[sum];
        }
    	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
    	int num;
    	StringBuilder output = new StringBuilder();
    	while(st.nextToken() == StreamTokenizer.TT_NUMBER && (num = (int)st.nval) != 0)
	        output.append(primesSumCount[num]).append('\n');
	    System.out.print(output);
	}
}
