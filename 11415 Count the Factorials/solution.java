import java.io.*;
import java.util.*;

public class Main {
    static int MAXN = 10000000;
    static int[] count = new int[MAXN + 1];
    static ArrayList<Integer> primes = new ArrayList<>();
    public static void main(String[] args) throws IOException {
        eulerSieve();
        for(int n = 3; n <= MAXN; ++n)
            count[n] += count[n - 1];
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int t = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(t-- > 0) {
            st.nextToken();
            output.append(binarySearch((int)st.nval)).append('\n');
        }
        System.out.print(output);
    }
    
    static void eulerSieve() {
        for(int n = 2; n <= MAXN; ++n) {
            if(count[n] == 0) {
                primes.add(n);
                count[n] = 1;
            }
            for(int i = 0, temp; (temp = primes.get(i) * n) <= MAXN; ++i) {
                count[temp] = count[primes.get(i)] + count[n];
                if(n % primes.get(i) == 0)
                    break;
            }
        }
    }
    
    static int binarySearch(int key) {
        int left = 3, right = MAXN;
        while(left <= right) {
            int mid = left + (right - left >> 1);
            if(count[mid] == key)
                return mid + 1;
            if(count[mid] < key)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
}
