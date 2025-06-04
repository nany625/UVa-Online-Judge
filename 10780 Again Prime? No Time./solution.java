import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 9999;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
    static ArrayList<Short> primes = new ArrayList<>();
    static ArrayList<Short>[] table = new ArrayList[MAX_NUM + 1];
    static int[] pfCount = new int[MAX_NUM + 1];
	public static void main(String[] args) throws IOException {
	    eulerSieve();
	    table[1] = new ArrayList<>();
	    for(int n = 2; n <= MAX_NUM; ++n)
	    	initTable(n);
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		st.nextToken();
		int cases = (int)st.nval;
		StringBuilder output = new StringBuilder();
		for(int i = 1; i <= cases; ++i) {
		    st.nextToken();
		    short m = (short)st.nval;
		    st.nextToken();
		    short n = (short)st.nval;
		    int min = MAX_NUM;
		    for(int j = 0; j < table[n].size() && min > 0 && m > 1; ++j) {
		        if(m % primes.get(j) == 0) {
		            int power = 0;
		            do {
		                ++power;
		                m /= primes.get(j);
		            } while(m % primes.get(j) == 0);
		            min = Math.min(min, table[n].get(j) / power);
		        }
		    }
		    if(m > 1 || min == MAX_NUM || min == 0)
		        output.append("Case ").append(i).append(":\nImpossible to divide\n");
		    else
		        output.append("Case ").append(i).append(":\n").append(min).append('\n');
		}
		System.out.print(output);
	}
	
	static void eulerSieve() {
		for(short n = 2; n <= MAX_NUM; ++n) {
			if(!isComposite[n])
				primes.add(n);
			for(int i = 0, temp; (temp = primes.get(i) * n) <= MAX_NUM; ++i) {
				isComposite[temp] = true;
				if(n % primes.get(i) == 0)
					break;
			}
		}
	}
	
	static void initTable(int n) {
        table[n] = new ArrayList<>(table[n - 1]);
        if(!isComposite[n]) 
            table[n].add((short)1);
        else {
            int temp = n;
            for(int i = 0; n > 1; ++i) {
                while(n % primes.get(i) == 0) {
                    table[temp].set(i, (short)(table[temp].get(i) + 1));
                    n /= primes.get(i);
                }
            }
        }
    }
}
