import java.io.*;
import java.util.*;

public class Main {
    public static void main(String args[]) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        st.nextToken();
        int N = (int)st.nval;
        StringBuilder output = new StringBuilder();
        while(N-- > 0) {
            String[] tokens = br.readLine().split("\\s+");
            int[] numbers = new int[tokens.length];
            for(int i = 0; i < tokens.length; ++i)
                numbers[i] = Integer.parseInt(tokens[i]);
            Arrays.sort(numbers);
            int max = 1;
            for(int i = tokens.length - 2; i >= 0 && numbers[i] > max; --i) {
                for(int j = tokens.length - 1; j > i; --j)
                    max = Math.max(max, GCD(numbers[i], numbers[j]));
            }
            output.append(max).append('\n');
        }
        System.out.print(output);
    }
    
    static int GCD(int i, int j) {
        return j == 0 ? i : GCD(j, i % j);
    }
}
