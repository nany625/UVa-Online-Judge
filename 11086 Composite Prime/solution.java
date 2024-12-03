import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 524288, MAX_N = 1048576;
    static boolean[] isComposite = new boolean[MAX_NUM + 1], isCompositePrime = new boolean[MAX_N + 1];
    static ArrayList<Integer> primes = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        primes.add(2);
        isCompositePrime[4] = true;
        for(int i = 3; i <= MAX_NUM; i += 2) {
            if(!isComposite[i]) {
                primes.add(i);
                for(int j = 0, temp; j < primes.size() && (temp = primes.get(j) * i) <= MAX_N; ++j)
                    isCompositePrime[temp] = true;
                if(i <= 724) {
                    for(int j = i * i; j <= MAX_NUM; j += i << 1)
                        isComposite[j] = true;
                }
            }
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
}
