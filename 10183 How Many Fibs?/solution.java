import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    static ArrayList<BigInteger> fib = new ArrayList<>();
    static BigInteger limit = BigInteger.TEN.pow(100);
    public static void main(String[] args) throws IOException {
        fib.add(BigInteger.ONE);
        fib.add(new BigInteger("2"));
        BigInteger next;
        while((next = fib.get(fib.size() - 2).add(fib.get(fib.size() - 1))).compareTo(limit) < 0)
            fib.add(next);
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        StringBuilder output = new StringBuilder();
        while((line = br.readLine()) != null) {
            String[] tokens = line.split("\\s+");
            if(tokens[0].equals("0") && tokens[1].equals("0"))
                break;
            int posA = binarySearch(new BigInteger(tokens[0])), posB = binarySearch(new BigInteger(tokens[1]));
            output.append(posB - posA + (posB < fib.size() && fib.get(posB).compareTo(new BigInteger(tokens[1])) == 0 ? 1 : 0)).append('\n');
        }
        System.out.print(output);
    }
    
    static int binarySearch(BigInteger key) {
        int left = 0, right = fib.size() - 1;
        while(left <= right) {
            int mid = left + (right - left >> 1);
            if(fib.get(mid).compareTo(key) == 0)
                return mid;
            if(fib.get(mid).compareTo(key) < 0)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return left;
    }
}
