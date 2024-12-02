import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 10000000;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
    static ArrayList<Integer> primes = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        primes.add(2);
        for(int i = 3; i <= MAX_NUM; i += 2) {
            if(!isComposite[i]) {
                primes.add(i);
                if(i <= 3162) {
                    for(int j = i * i; j <= MAX_NUM; j += i << 1)
                        isComposite[j] = true;
                }
            }
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        long N;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (N = (long)st.nval) != 0)
            output.append(solve(Math.abs(N))).append('\n');
        System.out.print(output);
    }
    
    static long solve(long n) {
        int limit = (int)Math.sqrt(n), count = 0;
        long max = 0;
        for(int i = 0; i < primes.size() && primes.get(i) <= limit; ++i) {
            if(n % primes.get(i) == 0) {
                ++count;
                max = primes.get(i);
                do {
                    n /= primes.get(i);
                } while(n % primes.get(i) == 0);
                limit = (int)Math.sqrt(n);
            }
        }
        if(n > 1) {
            ++count;
            max = n;
        }
        return count > 1 ? max : -1;
    }
}
