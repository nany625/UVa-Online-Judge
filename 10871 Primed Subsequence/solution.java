import java.io.*;
import java.util.*;

public class Main {
    static int MAX_NUM = 10000;
    static boolean[] isComposite = new boolean[MAX_NUM + 1];
    static ArrayList<Short> primes = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        eulerSieve();
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
    
    static void eulerSieve() {
	    isComposite[0] = isComposite[1] = true;
        for(short n = 2; n <= MAX_NUM; ++n) {
            if(!isComposite[n])
                primes.add(n);
            for(int i = 0, temp; (temp = primes.get(i) * n) <= MAX_NUM; ++i) {
                isComposite[temp] = true;
                if(n % primes.get(i) == 0)
                    break;
            }
        }
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
