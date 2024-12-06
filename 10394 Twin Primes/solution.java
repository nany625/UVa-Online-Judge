import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 20000000;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
    static ArrayList<Integer> primes = new ArrayList<>();
    static int[] twinPrimes = new int[100000];
    static int count = 1;
    public static void main(String[] args) throws IOException {
        twinPrimes[0] = 3;
        eulerSieve();
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER) {
            int S = (int)st.nval - 1;
            output.append('(').append(twinPrimes[S]).append(", ").append(twinPrimes[S] + 2).append(")\n");
        }
        System.out.print(output);
    }
    
    static void eulerSieve() {
        for(int n = 5; count < 100000 ; n += 4) {
            if(!isComposite[n])
                primes.add(n);
            for(int i = 0, temp; i < primes.size() && (temp = primes.get(i) * n) <= MAX_NUM; ++i) {
                isComposite[temp] = true;
                if(n % primes.get(i) == 0)
                    break;
            }
            n += 2;
            if(!isComposite[n])
                primes.add(n);
            for(int i = 0, temp; i < primes.size() && (temp = primes.get(i) * n) <= MAX_NUM; ++i) {
                isComposite[temp] = true;
                if(n % primes.get(i) == 0)
                    break;
            }
            if(!isComposite[n - 2] && !isComposite[n])
                twinPrimes[count++] = n - 2;
        }
    }
}
