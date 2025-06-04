import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 2703663;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
    static ArrayList<Integer> primes = new ArrayList<>();
    static int[] count = new int[MAX_NUM + 1];
	public static void main(String[] args) throws IOException {
	    eulerSieve();
	    for(int i = 2; i <= MAX_NUM; ++i)
	    	count[i] += count[i - 1];
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
		int cases = 0, N;
		StringBuilder output = new StringBuilder();
		while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (int)st.nval) >= 0) {
		    if(N == 0)
		        output.append("Case ").append(++cases).append(": 0!\n");
		    else {
		        int pos = binarySearch(N);
		        if(pos == -1)
		            output.append("Case ").append(++cases).append(": Not possible.\n");
		        else
		            output.append("Case ").append(++cases).append(": ").append(pos).append("!\n");
		    }
		}
		System.out.print(output);
	}
	
	static void eulerSieve() {
		for(int n = 2; n <= MAX_NUM; ++n) {
			if(!isComposite[n]) {
				primes.add(n);
				count[n] = 1;
			}
			for(int i = 0, temp; (temp = primes.get(i) * n) <= MAX_NUM; ++i) {
				isComposite[temp] = true;
				count[temp] = count[primes.get(i)] + count[n];
				if(n % primes.get(i) == 0)
					break;
			}
		}
	}
	
	static int binarySearch(int key) {
        int left = 2, right = MAX_NUM;
        while(left <= right) {
            int mid = left + (right - left >> 1);
            if(count[mid] == key)
                return mid;
            if(count[mid] < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return -1;
    }
}
