import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 10000;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
    static ArrayList<Short> primes = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        primes.add((short)2);
        for(short i = 4; i <= MAX_NUM; i += 2)
            isComposite[i] = true;
        for(short i = 3; i <= MAX_NUM; i += 2) {
            if(!isComposite[i]) {
                primes.add(i);
                if(i <= 100) {
                    for(int j = i * i; j <= MAX_NUM; j += i << 1)
                        isComposite[j] = true;
                }
            }
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int t = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(t-- > 0) {
            st.nextToken();
            int n = (int)st.nval;
            int[][] numbers = new int[2][n];
            for(int i = 0; i < n; ++i) {
                st.nextToken();
                numbers[0][i] = numbers[1][i] = (int)st.nval;
            }
            int length = 2;
            boolean antiPrimed = true;
            while(antiPrimed && length <= n) {
                for(int i = 0; i <= n - length && antiPrimed; ++i) {
                    numbers[1][i] += numbers[0][i + length - 1];
                    if((numbers[1][i] <= MAX_NUM && !isComposite[numbers[1][i]]) || (numbers[1][i] > MAX_NUM && isPrime(numbers[1][i]))) {
                        output.append("Shortest primed subsequence is length ").append(length).append(':');
                        for(int j = i; j < i + length; ++j)
                            output.append(' ').append(numbers[0][j]);
                        output.append('\n');
                        antiPrimed = false;
                    } 
                }
                ++length;
            }
            if(antiPrimed)
                output.append("This sequence is anti-primed.\n");
        }
        System.out.print(output);
    }
    
    static boolean isPrime(int n) {
        int limit = (int)Math.sqrt(n);
        for(int i = 0; i < primes.size() && primes.get(i) <= limit; ++i) {
            if(n % primes.get(i) == 0)
                return false;
        }
        return true;
    }
}
