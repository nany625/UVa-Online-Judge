import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StreamTokenizer st = new StreamTokenizer(br);
        long A;
        int cases = 0, L;
        StringBuilder output = new StringBuilder();
        while(st.nextToken() == StreamTokenizer.TT_NUMBER && (A = (long)st.nval) >= 0 && st.nextToken() == StreamTokenizer.TT_NUMBER && (L = (int)st.nval) >= 0) {
            output.append("Case ").append(++cases).append(": A = ").append(A).append(", limit = ").append(L).append(", number of terms = ");
            int terms = 0;
            while(A != 1 && A <= L) {
                ++terms;
                A = (A & 1) == 1 ? 3 * A + 1 : A >> 1;
            }
            output.append(terms + (A == 1 ? 1 : 0)).append('\n');
        }
        System.out.print(output);
    }
}
