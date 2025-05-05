import java.io.*;
import java.math.*;

public class Main {
    static int MAXN = 10000;
    static BigInteger[] ans = new BigInteger[MAXN + 1];
    public static void main(String[] args) throws IOException {
        ans[0] = BigInteger.ZERO;
        BigInteger temp = BigInteger.ONE;
        int N = 1, count = 1;
        while(N <= MAXN) {
            for(int i = 1; i <= count && N <= MAXN; ++i, ++N)
                ans[N] = ans[N - 1].add(temp);
            temp = temp.multiply(new BigInteger("2"));
            ++count;
        }
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StreamTokenizer st = new StreamTokenizer(br);
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER)
            output.append(ans[(int)st.nval]).append('\n');
        System.out.print(output);
    }
}
