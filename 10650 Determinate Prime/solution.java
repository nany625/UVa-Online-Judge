import java.io.*;
import java.util.*;

public class Main {
    static short MAX_NUM = 32000;
    static boolean[] isComposite = new boolean[(MAX_NUM >> 1) + 1];
    static ArrayList<Short> primes = new ArrayList<>();
    static ArrayList<dtPrime> determinatePrimes = new ArrayList<>();
	public static void main(String[] args) throws IOException {
		eulerSieve();
		for(int i = 1; i < primes.size() - 1; ++i) {
		    if(primes.get(i) << 1 == primes.get(i - 1) + primes.get(i + 1)) {
		        determinatePrimes.add(new dtPrime());
		        determinatePrimes.get(determinatePrimes.size() - 1).start = primes.get(i - 1);
		        do {
		            ++i;
		        } while(i < primes.size() - 1 && primes.get(i) << 1 == primes.get(i - 1) + primes.get(i + 1));
		        determinatePrimes.get(determinatePrimes.size() - 1).end = primes.get(i);
		        determinatePrimes.get(determinatePrimes.size() - 1).step = (short)(primes.get(i) - primes.get(i - 1));
		    }
		}
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
		    short x = (short)st.nval;
		    st.nextToken();
		    short y = (short)st.nval;
		    if(x == 0 && y == 0)
		        break;
		    if(x > y) {
		    	short temp = x;
		    	x = y;
		    	y = temp;
		    }
		    int pos = binarySearch(x);
		    while(pos < determinatePrimes.size() && determinatePrimes.get(pos).end <= y) {
		        for(short i = determinatePrimes.get(pos).start; i < determinatePrimes.get(pos).end; i += determinatePrimes.get(pos).step)
		            output.append(i).append(' ');
		        output.append(determinatePrimes.get(pos).end).append('\n');
		        ++pos;
		    }
		}
		System.out.print(output);
	}
	
	static void eulerSieve() {
	    for(short n = 3; n <= MAX_NUM; n += 2) {
	        if(!isComposite[n >> 1])
	            primes.add(n);
	        for(int i = 0, temp; i < primes.size() && (temp = primes.get(i) * n) <= MAX_NUM; ++i) {
	            isComposite[temp >> 1] = true;
	            if(n % primes.get(i) == 0)
	                break;
	        }
	    }
	}
	
	static int binarySearch(short key) {
	    int left = 0, right = determinatePrimes.size() - 1;
	    while(left <= right) {
	        int mid = left + (right - left >> 1);
	        if(determinatePrimes.get(mid).start == key)
	            return mid;
	        if(determinatePrimes.get(mid).start < key)
	            left = mid + 1;
	        else
	            right = mid - 1;
	    }
	    return left;
	}
}

class dtPrime {
    short start, end, step;
}
