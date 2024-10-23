import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
    static ArrayList<BigInteger> fib = new ArrayList<>();
    static BigInteger limit = BigInteger.TEN.pow(100);
    public static void main(String[] args) throws IOException {
        fib.add(BigInteger.ONE);
        fib.add(new BigInteger("2"));
        int size = 2;
        BigInteger next;
        while((next = fib.get(size - 2).add(fib.get(size - 1))).compareTo(limit) < 0) {
            fib.add(next);
            ++size;
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String line;
        StringBuilder output = new StringBuilder();
        while((line = br.readLine()) != null) {
            String[] tokens = line.split("\\s+");
            if(tokens[0].equals("0") && tokens[1].equals("0"))
                break;
            int posA = binarySearch(size, new BigInteger(tokens[0])), posB = binarySearch(size, new BigInteger(tokens[1]));
            output.append(posB - posA + (posB < size && fib.get(posB).compareTo(new BigInteger(tokens[1])) == 0 ? 1 : 0)).append('\n');
        }
        System.out.print(output);
    }
    
    static int binarySearch(int size, BigInteger key) {
        int left = 0, right = size - 1;
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
