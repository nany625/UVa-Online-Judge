import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 99999;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
    static ArrayList<Integer> primes = new ArrayList<>();
	public static void main(String[] args) throws IOException {
	    eulerSieve();
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s;
		StringBuilder output = new StringBuilder();
		while((s = br.readLine()) != null && !s.equals("0")) {
		    int max = 0;
		    boolean found = false;
		    for(int i = Math.min(s.length(), 5); !found; --i) {
		        for(int j = 0; j <= s.length() - i; ++j) {
		            int num = Integer.parseInt(s.substring(j, j + i));
		            if(!isComposite[num]) {
		                max = Math.max(max, num);
		                found = true;
		            }
		        }
		    }
		    output.append(max).append('\n');
		}
            
		System.out.print(output);
	}
	
	static void eulerSieve() {
	    isComposite[0] = isComposite[1] = true;
		for(int n = 2; n <= MAX_NUM; ++n) {
			if(!isComposite[n])
				primes.add(n);
			for(int i = 0, temp; i < primes.size() && (temp = primes.get(i) * n) <= MAX_NUM; ++i) {
				isComposite[temp] = true;
				if(n % primes.get(i) == 0)
					break;
			}
		}
	}
}
