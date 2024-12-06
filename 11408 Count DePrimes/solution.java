import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 5000000;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
    static ArrayList<Integer> primes = new ArrayList<>();
    static int[] sum = new int[MAX_NUM + 1], count = new int[MAX_NUM + 1];
	public static void main(String[] args) throws IOException {
	    eulerSieve();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int a;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (a = (int)st.nval) != 0) {
            st.nextToken();
            output.append(count[(int)st.nval] - count[a - 1]).append('\n');
        }
        System.out.print(output);
	}
	
	static void eulerSieve() {
        for(int n = 2; n <= MAX_NUM; ++n) {
            if(!isComposite[n])
                primes.add(sum[n] = n);
            for(int i = 0, temp; i < primes.size() && (temp = primes.get(i) * n) <= MAX_NUM; ++i) {
                isComposite[temp] = true;
                if(n % primes.get(i) == 0) {
                    sum[temp] = sum[n];
                    break;
                } else
                    sum[temp] = sum[n] + primes.get(i);
            }
            count[n] = count[n - 1] + (!isComposite[sum[n]] ? 1 : 0);
        }
    }
}
