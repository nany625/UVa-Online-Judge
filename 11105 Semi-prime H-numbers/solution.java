import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 1000001;
    static boolean[] isHComposite = new boolean[(MAX_NUM >> 2) + 1], isHSemiPrime = new boolean[MAX_NUM + 1];
    static int[] ans = new int[MAX_NUM + 1];
    static ArrayList<Integer> hPrimes = new ArrayList<>();
	public static void main(String[] args) throws IOException {
	    eulerSieve();
	    for(int i = 0; i < hPrimes.size(); ++i) {
            for(int j = 0, temp; j < hPrimes.size() && (temp = hPrimes.get(i) * hPrimes.get(j)) <= MAX_NUM; ++j)
                isHSemiPrime[temp] = true;
        }
        for(int i = 1; i <= MAX_NUM; ++i)
            ans[i] = ans[i - 1] + (isHSemiPrime[i] ? 1 : 0);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        int h;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (h = (int)st.nval) != 0)
            output.append(h).append(' ').append(ans[h]).append('\n');
        System.out.print(output);
	}
    
    static void eulerSieve() {
        for(int n = 5; n <= MAX_NUM; n += 4) {
            if(!isHComposite[n >> 2])
                hPrimes.add(n);
            for(int i = 0, temp; (temp = hPrimes.get(i) * n) <= MAX_NUM; ++i) {
                isHComposite[temp >> 2] = true;
                if(n % hPrimes.get(i) == 0)
                    break;
            }
        }
    }
}
