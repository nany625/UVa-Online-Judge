import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        StreamTokenizer st = new StreamTokenizer(System.in);
        long A;
        int cases = 0, L;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (A = (long)st.nval) >= 0 && st.nextToken() == StreamTokenizer.TT_NUMBER && (L = (int)st.nval) >= 0) {
            output.append("Case " + (++cases) + ": A = " + A + ", limit = " + L + ", number of terms = ");
            int terms = 0;
            while(A != 1 && A <= L) {
                ++terms;
                A = A % 2 == 0 ? A / 2 : 3 * A + 1;
            }
            output.append(terms + (A == 1 ? 1 : 0) + "\n");
        }
        System.out.print(output);
    }
}
