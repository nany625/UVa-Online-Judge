import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 524288, MAX_N = 1048576;
    static boolean[] isComposite = new boolean[(MAX_NUM >> 1) + 1], isCompositePrime = new boolean[MAX_N + 1];
    static ArrayList<Integer> primes = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        eulerSieve();
        for(int i = 0; i < primes.size(); ++i) {
            for(int j = 0, temp; j < primes.size() && (temp = primes.get(i) * primes.get(j)) <= MAX_N; ++j)
                isCompositePrime[temp] = true;
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int N = (int)st.nval, count = 0;
            while(N-- > 0) {
                st.nextToken();
                if(isCompositePrime[(int)st.nval])
                    ++count;
            }
            output.append(count).append('\n');
        }
        System.out.print(output);
    }
    
    static void eulerSieve() {
        primes.add(2);
        for(int n = 3; n <= MAX_NUM; n += 2) {
            if(!isComposite[n >> 1])
                primes.add(n);
            for(int i = 1, temp; (temp = primes.get(i) * n) <= MAX_NUM; ++i) {
                isComposite[temp >> 1] = true;
                if(n % primes.get(i) == 0)
                    break;
            }
        }
    }
}
