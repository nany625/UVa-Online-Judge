import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 1000001;
    static boolean[] isHComposite = new boolean[MAX_NUM + 1], isHSemiPrime = new boolean[MAX_NUM + 1];
    static int[] ans = new int[MAX_NUM + 1];
    static ArrayList<Integer> hPrimes = new ArrayList<>();
	public static void main(String[] args) throws IOException {
	    for(int i = 5; i <= MAX_NUM; i += 4) {
            if(!isHComposite[i]) {
                hPrimes.add(i);
                for(int j = 0, temp; j < hPrimes.size() && (temp = hPrimes.get(j) * i) <= MAX_NUM; ++j)
                    isHSemiPrime[temp] = true;
                if(i <= 1000) {
                    for(int j = i * i; j <= MAX_NUM; j += i << 2)
                        isHComposite[j] = true;
                }
            }
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
}
