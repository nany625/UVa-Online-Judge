import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 1000000;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
    static ArrayList<Integer> primes = new ArrayList<>();
    static int[] ans = new int[MAX_NUM + 1];
	public static void main(String[] args) throws IOException {
	    eulerSieve();
	    for(int i = 2; i <= MAX_NUM; ++i)
	    	ans[i] += ans[i - 1];
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER)
    		output.append(ans[(int)st.nval]).append('\n');
		System.out.print(output);
	}
	
	static void eulerSieve() {
		for(int n = 2; n <= MAX_NUM; ++n) {
			if(!isComposite[n]) {
				primes.add(n);
				ans[n] = 1;
			}
			for(int i = 0, temp; i < primes.size() && (temp = primes.get(i) * n) <= MAX_NUM; ++i) {
				isComposite[temp] = true;
				ans[temp] = ans[primes.get(i)] + ans[n];
				if(n % primes.get(i) == 0)
					break;
			}
		}
	}
}
